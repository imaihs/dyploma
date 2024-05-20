#include <string.h>
#include "main.h"
#include "os.h"
#include "log.h"
#include "d2d.h"
#include "sensors.h"

CREATE_TASK(d2d, osPriorityNormal, 1024, d2d_task, NULL);

extern UART_HandleTypeDef d2d_uart;

static uint8_t d2d_calc_crc8(uint8_t *data, uint8_t size)
{
    uint8_t crc = 0x5a;
    while (size--)
    {
        crc ^= *data++;
    }
    return crc;
}

static void d2d_task(void *argument)
{
    (void)argument;
    struct sensors sens;
    union d2d_payload payload;
    static uint8_t sequence = 0;

    for (;;)
    {
        sens = get_sensors_data();
        memcpy(payload.body.buf, &sens, sizeof(sens));
        payload.body.crc = d2d_calc_crc8(payload.body.buf, sizeof(sens));

        payload.header.flags = 0;
        payload.header.len = sizeof(sens) + 1;
        payload.header.seq = sequence++;
        payload.header.crc = d2d_calc_crc8(&payload.data[1], sizeof(payload.header) - 1);

        HAL_UART_Transmit_DMA(&d2d_uart, (uint8_t *)payload.data, sizeof(payload.header) + payload.header.len);
        LOG("HEAD: %02X %02X %02X %02X", payload.header.crc, payload.header.flags, payload.header.len, payload.header.seq);
        LOG("BODY: %02X %02X %02X %02X", payload.body.crc, payload.body.buf[0], payload.body.buf[1], payload.body.buf[2]);
        // LOG("yeah");
        osDelay(1000);
    }
}
