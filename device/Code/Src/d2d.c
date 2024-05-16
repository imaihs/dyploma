#include "main.h"
#include "os.h"
#include "log.h"
#include "d2d.h"

CREATE_TASK(d2d, osPriorityNormal, 512, d2d_task, NULL);

extern UART_HandleTypeDef d2d_uart;

static void d2d_task(void *argument)
{
    (void)argument;
    uint8_t buffer[16] = "0123456789abcdef";
    for (;;)
    {
    	HAL_UART_Transmit_DMA(&d2d_uart, (uint8_t *)buffer, 16);
    	LOG("yeah");
        osDelay(1000);
    }
}
