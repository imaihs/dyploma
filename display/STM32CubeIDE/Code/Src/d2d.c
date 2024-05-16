#include "main.h"
#include "os.h"
#include "log.h"
#include "d2d.h"

CREATE_TASK(d2d, osPriorityNormal, 1024, d2d_task, NULL);
CREATE_SEMAPHORE(d2d_rxcplt_sem, 1);

extern UART_HandleTypeDef d2d_uart;

static char buffer[64] = {0};

static void d2d_task(void *argument)
{
    (void)argument;
    init_d2d_rxcplt_sem();
    HAL_UART_DMAStop(&d2d_uart);
    HAL_UART_DeInit(&d2d_uart);
    HAL_UART_Init(&d2d_uart);
    __HAL_UART_ENABLE_IT(&d2d_uart, UART_IT_IDLE);
    HAL_UART_DMAStop(&d2d_uart);
    HAL_UART_Receive_DMA(&d2d_uart, (uint8_t *)buffer, 64);
    for (;;)
    {
        osSemaphoreAcquire(d2d_rxcplt_sem, osWaitForever);
        LOG("%u dma %s", HAL_DMA_GetState(d2d_uart.hdmarx), buffer);
        osDelay(1);
    }
}

extern UART_HandleTypeDef huart1;
void HAL_UART_RxIdleCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        HAL_UART_Transmit(&huart1, (uint8_t *) "idle\r\n", 7, 1);
        // osSemaphoreRelease(d2d_rxcplt_sem);
    }
}

void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        osSemaphoreRelease(d2d_rxcplt_sem);
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        osSemaphoreRelease(d2d_rxcplt_sem);
    }
}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if (huart == &d2d_uart)
    {
        HAL_UART_DMAResume(huart);
        HAL_UART_Receive_DMA(&d2d_uart, (uint8_t *)buffer, 16);
    }
}
