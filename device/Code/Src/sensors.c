#include "cmsis_os.h"
#include "sensors.h"
#include "stm32l475e_iot01_tsensor.h"
#include "stm32l475e_iot01_hsensor.h"
#include "stm32l475e_iot01_psensor.h"
#include "log.h"
#include "os.h"

CREATE_TASK(temperature, osPriorityNormal, 512, temperature_task, NULL);
CREATE_TASK(humidity, osPriorityNormal, 512, humidity_task, NULL);
CREATE_TASK(pressure, osPriorityNormal, 512, pressure_task, NULL);

static struct temperature get_temperature(void);
static struct humidity get_humidity(void);
static struct pressure get_pressure(void);

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
    LOG("temperature is %d.%d", t.temp, t.temp_float);
    osDelay(1000);
  }
}

static void humidity_task(void *argument)
{
  while (BSP_HSENSOR_Init() != HSENSOR_OK)
  {
    osDelay(1000);
  }

  struct humidity h;
  for (;;)
  {
    h = get_humidity();
    LOG("humidity is %d.%d", h.hum, h.hum_float);
    osDelay(1000);
  }
}

static void pressure_task(void *argument)
{
  while (BSP_PSENSOR_Init() != PSENSOR_OK)
  {
    osDelay(1000);
  }

  struct pressure p;
  for (;;)
  {
    p = get_pressure();
    LOG("pressure is %d.%d", p.pres, p.pres_float);
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

static struct humidity get_humidity(void)
{
  struct humidity h;
  float tmp = BSP_HSENSOR_ReadHumidity();
  h.hum = (int)tmp;
  h.hum_float = (uint16_t)(tmp * 10) % 10;
  return h;
}

static struct pressure get_pressure(void)
{
  struct pressure p;
  float tmp = BSP_PSENSOR_ReadPressure();
  p.pres = (int)tmp;
  p.pres_float = (uint16_t)(tmp * 10) % 10;
  return p;
}
