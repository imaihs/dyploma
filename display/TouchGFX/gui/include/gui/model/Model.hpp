#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void setTemperature(int temp, unsigned temp_float);
    int getTemperature() const;
    unsigned getTemperatureFloat() const;
    void setHumidity(int hum, unsigned hum_float);
    int getHumidity() const;
    unsigned getHumidityFloat() const;
    void setPressure(int pres, unsigned pres_float);
    int getPressure() const;
    unsigned getPressureFloat() const;

protected:
    ModelListener* modelListener;

    int temperature;
    unsigned temperatureFloat;
    int humidity;
    unsigned humidityFloat;
    int pressure;
    unsigned pressureFloat;
};

#endif // MODEL_HPP
