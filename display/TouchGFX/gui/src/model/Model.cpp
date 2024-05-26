#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR
extern "C" {
#include "sensors.h"
}
#endif /*SIMULATOR*/

Model::Model() : 
        modelListener(0),
        temperature(20),
        temperatureFloat(0),
        humidity(20),
        humidityFloat(0),
        pressure(20),
        pressureFloat(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR
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
