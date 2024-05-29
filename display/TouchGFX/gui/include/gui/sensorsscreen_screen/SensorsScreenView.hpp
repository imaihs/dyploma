#ifndef SENSORSSCREENVIEW_HPP
#define SENSORSSCREENVIEW_HPP

#include <gui_generated/sensorsscreen_screen/SensorsScreenViewBase.hpp>
#include <gui/sensorsscreen_screen/SensorsScreenPresenter.hpp>

class SensorsScreenView : public SensorsScreenViewBase
{
public:
    SensorsScreenView();
    virtual ~SensorsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    void updateTime(unsigned hour, unsigned minute, unsigned second);
protected:
    int currentTemp;
    unsigned currentTempFloat;
    int currentHumidity;
    unsigned currentHumidityFloat;
    int currentPressure;
    unsigned currentPressureFloat;
};

#endif // SENSORSSCREENVIEW_HPP
