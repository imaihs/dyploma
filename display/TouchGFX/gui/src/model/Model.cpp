#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
extern "C" {
#include "sensors.h"

extern unsigned flagOnePerSecond;
extern RTC_TimeTypeDef RTCGetTime();
extern void RTCSetTime(unsigned hours, unsigned minutes, unsigned seconds);
extern RTC_DateTypeDef RTCGetDate();
extern void RTCSetDate(unsigned day, unsigned month, unsigned year);
}
#endif /*SIMULATOR*/

Model::Model() : 
        modelListener(0),
        temperature(21),
        temperatureFloat(3),
        humidity(46),
        humidityFloat(8),
        pressure(1057),
        pressureFloat(9)
{

}

void Model::tick()
{
#ifndef SIMULATOR
    if(flagOnePerSecond != 0) {
        flagOnePerSecond = 0;
        RTC_TimeTypeDef sTime = RTCGetTime();
        modelListener->updateTime(sTime.Hours, sTime.Minutes, sTime.Seconds);
    }
    struct sensors s = sensors_get_data();
    setTemperature(s.t.temp, s.t.temp_float);
    setHumidity(s.h.hum, s.h.hum_float);
    setPressure(s.p.pres, s.p.pres_float);
#endif /*SIMULATOR*/
}

void Model::setTemperature(int temp, unsigned temp_float)
{
    temperature = temp;
    temperatureFloat = temp_float;
}

int Model::getTemperature() const
{
    return temperature;
}

unsigned Model::getTemperatureFloat() const
{
    return temperatureFloat;
}

void Model::setHumidity(int hum, unsigned hum_float)
{
    humidity = hum;
    humidityFloat = hum_float;
}

int Model::getHumidity() const
{
    return humidity;
}

unsigned Model::getHumidityFloat() const
{
    return humidityFloat;
}

void Model::setPressure(int pres, unsigned pres_float)
{
    pressure = pres;
    pressureFloat = pres_float;
}

int Model::getPressure() const
{
    return pressure;
}

unsigned Model::getPressureFloat() const
{
    return pressureFloat;
}

void Model::GetTime()
{
#ifndef SIMULATOR
    RTC_TimeTypeDef sTime = RTCGetTime();
    modelListener->updateTime(sTime.Hours, sTime.Minutes, sTime.Seconds);
    modelListener->peekTime(sTime.Hours, sTime.Minutes, sTime.Seconds);
#endif /*SIMULATOR*/
}

void Model::SetTime(unsigned hours, unsigned minutes, unsigned seconds)
{
#ifndef SIMULATOR
    RTCSetTime(hours, minutes, seconds);
#endif /*SIMULATOR*/
}

void Model::GetDate()
{
#ifndef SIMULATOR
    RTC_DateTypeDef sDate = RTCGetDate();
    modelListener->updateDate(sDate.WeekDay, sDate.Date, sDate.Month, sDate.Year);
    modelListener->peekDate(sDate.WeekDay, sDate.Date, sDate.Month, sDate.Year);
#endif /*SIMULATOR*/
}

void Model::SetDate(unsigned day, unsigned month, unsigned year)
{
#ifndef SIMULATOR
    RTCSetDate(day, month, year);
#endif /*SIMULATOR*/
}