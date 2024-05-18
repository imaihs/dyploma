#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include "cmsis_os.h"
#include "main.h"
#include "log.h"
#include "os.h"
#include "ringbuf.h"

CREATE_TASK(log, osPriorityNormal, 2048, log_task, NULL);
CREATE_RINGBUF(log_ringbuf, LOG_BUFFER_SIZE);
CREATE_SEMAPHORE(log_txcplt_sem, 1);

extern UART_HandleTypeDef huart1;

void log_init(void)
{
    init_log_ringbuf();
    init_log_txcplt_sem();
}

void LOG(const char *format, ...)
{
    int err;
    va_list args;
    va_start(args, format);
    uint8_t endline[2] = "\r\n";

    char temp_buffer[LOG_MAX_SIZE];
    int len = vsnprintf(temp_buffer, LOG_MAX_SIZE, format, args);

    err = ringbuf_put(&log_ringbuf, (uint8_t *)temp_buffer, len);
    va_end(args);
    if (err != 0)
    {
        HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"log error\r\n", 13);
    }
    err = ringbuf_put(&log_ringbuf, endline, 2);
    if (err != 0)
    {
        HAL_UART_Transmit_DMA(&huart1, (uint8_t *)"log error\r\n", 13);
    }
}

static void log_task(void *argument)
{
    char buffer[LOG_BUFFER_SIZE + 1];
    size_t size;
    int err;

    for (;;)
    {
        size = ringbuf_get_msg_size(&log_ringbuf);
        while (size > 0)
        {
            err = ringbuf_get(&log_ringbuf, (uint8_t *)buffer, &size);
            if (err != 0 || size <= 0)
            {
                break;
            }

            buffer[size++] = '\0';
            HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buffer, size);
            osSemaphoreAcquire(log_txcplt_sem, osWaitForever);
            size = ringbuf_get_msg_size(&log_ringbuf);
        }
        osDelay(5);
    }
}

void log_txcplt_cb(void)
{
    osSemaphoreRelease(log_txcplt_sem);
}
