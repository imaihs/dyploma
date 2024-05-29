#include <gui/sensorsscreen_screen/SensorsScreenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SensorsScreenView::SensorsScreenView() :
        currentTemp(0), currentTempFloat(0),
        currentHumidity(0), currentHumidityFloat(0),
        currentPressure(0), currentPressureFloat(0)
{

}

void SensorsScreenView::setupScreen()
{
    SensorsScreenViewBase::setupScreen();
    presenter->UIGetTime();
}

void SensorsScreenView::tearDownScreen()
{
    SensorsScreenViewBase::tearDownScreen();
}

void SensorsScreenView::handleTickEvent()
{
    int newTemp = presenter->getTemperature();
    unsigned newTempFloat = presenter->getTemperatureFloat();
    int newHumidity = presenter->getHumidity();
    unsigned newHumidityFloat = presenter->getHumidityFloat();
    int newPressure = presenter->getPressure();
    unsigned newPressureFloat = presenter->getPressureFloat();

    if (newTemp != currentTemp || newTempFloat != currentTempFloat)
    {
        currentTemp = newTemp;
        currentTempFloat = newTempFloat;

        Unicode::snprintf(tempTextBuffer1, TEMPTEXTBUFFER1_SIZE, "%d", currentTemp);
        Unicode::snprintf(tempTextBuffer2, TEMPTEXTBUFFER2_SIZE, "%d", currentTempFloat);
        tempText.setWildcard1(tempTextBuffer1);
        tempText.setWildcard2(tempTextBuffer2);
        tempText.invalidate();
    }

    if (newHumidity != currentHumidity || newHumidityFloat != currentHumidityFloat)
    {
        currentHumidity = newHumidity;
        currentHumidityFloat = newHumidityFloat;

        Unicode::snprintf(humTextBuffer1, HUMTEXTBUFFER1_SIZE, "%d", newHumidity);
        Unicode::snprintf(humTextBuffer2, HUMTEXTBUFFER2_SIZE, "%d", newHumidityFloat);
        humText.setWildcard1(humTextBuffer1);
        humText.setWildcard2(humTextBuffer2);
        humText.invalidate();
    }

    if (newPressure != currentPressure || newPressureFloat != currentPressureFloat)
    {
        currentPressure = newPressure;
        currentPressureFloat = newPressureFloat;

        Unicode::snprintf(presTextBuffer1, PRESTEXTBUFFER1_SIZE, "%d", newPressure);
        Unicode::snprintf(presTextBuffer2, PRESTEXTBUFFER2_SIZE, "%d", newPressureFloat);
        presText.setWildcard1(presTextBuffer1);
        presText.setWildcard2(presTextBuffer2);
        presText.invalidate();
    }
}

void SensorsScreenView::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    topPanel1.updateTime(hour, minute, second);
}
