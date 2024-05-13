#include "cmsis_os.h"
#include "sensors.h"
#include "stm32l475e_iot01_tsensor.h"
#include "log.h"
#include "os.h"

CREATE_TASK(temperature, osPriorityNormal, 512, temperature_task, NULL);

static struct temperature get_temperature(void);

static void temperature_task(void *argument)
{
  while (BSP_TSENSOR_Init() != TSENSOR_OK)
  {
    osDelay(1000);
  }

  struct temperature t;
  for (;;)
  {
    t = get_temperature();
    LOG("temp is %d.%d", t.temp, t.temp_float);
    osDelay(1000);
  }
}

static struct temperature get_temperature(void)
{
  struct temperature t;
  float tmp = BSP_TSENSOR_ReadTemp();
  t.temp = (int)tmp;
  t.temp_float = (uint16_t)(tmp * 10) % 10;
  return t;
}
