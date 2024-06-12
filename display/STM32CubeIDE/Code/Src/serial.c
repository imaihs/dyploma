#include "main.h"
#include "os.h"
#include "log.h"
#include "serial.h"
#include "ringbuf.h"

CREATE_TASK(serial, osPriorityNormal, 1024, serial_task, NULL);
CREATE_RINGBUF(serial_ringbuf, SERIAL_RINGBUFF_SIZE);
CREATE_SEMAPHORE(serial_rxcplt_sem, 1);

extern UART_HandleTypeDef d2d_uart;
static uint8_t uart_rx_dma_buff[SERIAL_RX_BUFFER_SIZE] = {0};

static void usart_rx_check(void)
{
    static size_t old_pos;
    size_t pos;
    int err;

    pos = SERIAL_RX_BUFFER_SIZE - __HAL_DMA_GET_COUNTER(d2d_uart.hdmarx);
    if (pos != old_pos)
    {
        if (pos > old_pos)
        {
            err = ringbuf_put(&serial_ringbuf, &uart_rx_dma_buff[old_pos], pos - old_pos);
            if (err != 0)
            {
                LOG("Error. Cannot put data in serial_ringbuf");
            }
        }
        else
        {
            err = ringbuf_put(&serial_ringbuf, &uart_rx_dma_buff[old_pos], SERIAL_RX_BUFFER_SIZE - old_pos);
            if (err != 0)
            {
                LOG("Error. Cannot put data in serial_ringbuf");
            }
            if (pos > 0)
            {
                err = ringbuf_put(&serial_ringbuf, &uart_rx_dma_buff[0], pos);
                if (err != 0)
                {
                    LOG("Error. Cannot put data in serial_ringbuf");
                }
            }
        }
        old_pos = pos;
    }
}

static void serial_task(void *argument)
{
    (void)argument;
    init_serial_rxcplt_sem();
    HAL_UART_DMAStop(&d2d_uart);
    HAL_UART_DeInit(&d2d_uart);
    HAL_UART_Init(&d2d_uart);
    __HAL_UART_ENABLE_IT(&d2d_uart, UART_IT_IDLE);
    HAL_UART_DMAStop(&d2d_uart);
    HAL_UART_Receive_DMA(&d2d_uart, (uint8_t *)uart_rx_dma_buff, SERIAL_RX_BUFFER_SIZE);
    for (;;)
    {
        osSemaphoreAcquire(serial_rxcplt_sem, osWaitForever);
        usart_rx_check();
        osDelay(1);
    }
}

void HAL_UART_RxIdleCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        osSemaphoreRelease(serial_rxcplt_sem);
    }
}

void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        osSemaphoreRelease(serial_rxcplt_sem);
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        osSemaphoreRelease(serial_rxcplt_sem);
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        HAL_UART_DMAResume(huart);
        HAL_UART_Receive_DMA(huart, (uint8_t *)uart_rx_dma_buff, SERIAL_RX_BUFFER_SIZE);
    }
}
