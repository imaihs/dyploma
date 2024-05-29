#include <gui/sensorsscreen_screen/SensorsScreenView.hpp>
#include <gui/sensorsscreen_screen/SensorsScreenPresenter.hpp>

SensorsScreenPresenter::SensorsScreenPresenter(SensorsScreenView& v)
    : view(v)
{

}

void SensorsScreenPresenter::activate()
{

}

void SensorsScreenPresenter::deactivate()
{

}

int SensorsScreenPresenter::getTemperature() const
{
    return model->getTemperature();
}

unsigned SensorsScreenPresenter::getTemperatureFloat() const
{
    return model->getTemperatureFloat();
}

int SensorsScreenPresenter::getHumidity() const
{
    return model->getHumidity();
}

unsigned SensorsScreenPresenter::getHumidityFloat() const
{
    return model->getHumidityFloat();
}

int SensorsScreenPresenter::getPressure() const
{
    return model->getPressure();
}

unsigned SensorsScreenPresenter::getPressureFloat() const
{
    return model->getPressureFloat();
}

void SensorsScreenPresenter::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    view.updateTime(hour, minute, second);
}

void SensorsScreenPresenter::UIGetTime(void)
{
    model->GetTime();
}