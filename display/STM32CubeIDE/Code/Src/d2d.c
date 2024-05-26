#include "main.h"
#include "d2d.h"
#include "os.h"
#include "log.h"
#include "serial.h"
#include "ringbuf.h"
#include "sensors.h"

CREATE_TASK(d2d, osPriorityNormal, 2048, d2d_task, NULL);

extern struct ringbuf serial_ringbuf;

static struct sensors sensors_data;

struct sensors sensors_get_data(void) {
    return sensors_data;
}

static uint8_t d2d_calc_crc8(uint8_t *data, uint8_t size)
{
    uint8_t crc = 0x5a;
    while (size--)
    {
        crc ^= *data++;
    }
    return crc;
}

static void d2d_proceed_pkt(uint8_t *data, size_t size)
{
    if (size == sizeof(struct sensors))
    {
        sensors_data = *((struct sensors *)data);
        struct sensors s = sensors_data;
        LOG("temperature is %d.%d", s.t.temp, s.t.temp_float);
        LOG("humidity is %d.%d", s.h.hum, s.h.hum_float);
        LOG("pressure is %d.%d", s.p.pres, s.p.pres_float);
    }
}

static void d2d_task(void *argument)
{
    (void)argument;
    int err;
    size_t size;
    union d2d_payload payload;
    for (;;)
    {
        size = ringbuf_get_size(&serial_ringbuf);
        if (size < sizeof(payload.header))
        {
            goto d2d_loop;
        }

        size_t bytes_read = 0;
        size_t bytes_to_read = sizeof(payload.header);
        while (bytes_to_read != 0)
        {
            err = ringbuf_get(&serial_ringbuf, (uint8_t *)&payload.data[bytes_read], &bytes_to_read);
            if (err != 0)
            {
                LOG("ERROR. Get from serial_ringbuf");
                goto d2d_loop;
            }

            bytes_read += bytes_to_read;
            bytes_to_read = sizeof(payload.header) - bytes_read;
        }

        LOG("HEAD: %02X %02X %02X %02X", payload.header.crc, payload.header.flags, payload.header.len, payload.header.seq);

        uint8_t crc = d2d_calc_crc8(&payload.data[1], sizeof(payload.header) - 1);
        if (crc != payload.header.crc)
        {
            LOG("ERROR. Bad header crc");
            ringbuf_clear(&serial_ringbuf);
            goto d2d_loop;
        }

        bytes_read = 0;
        bytes_to_read = payload.header.len;

        size = ringbuf_get_size(&serial_ringbuf);
        while (size < bytes_to_read)
        {
            osDelay(5);
            size = ringbuf_get_size(&serial_ringbuf);
        }

        while (bytes_to_read != 0)
        {
            err = ringbuf_get(&serial_ringbuf, (uint8_t *)&payload.data[bytes_read + sizeof(payload.header)], &bytes_to_read);
            if (err != 0)
            {
                LOG("ERROR. Get from serial_ringbuf");
                goto d2d_loop;
            }

            bytes_read += bytes_to_read;
            bytes_to_read = payload.header.len - bytes_read;
        }

        LOG("BODY: %02X %02X %02X %02X", payload.body.crc, payload.body.buf[0], payload.body.buf[1], payload.body.buf[2]);

        crc = d2d_calc_crc8(payload.body.buf, bytes_read - 1);
        if (crc != payload.body.crc)
        {
            LOG("ERROR. Bad body crc");
            goto d2d_loop;
        }

        d2d_proceed_pkt(payload.body.buf, bytes_read - 1);

    d2d_loop:
        osDelay(100);
    }
}
