#ifndef SENSORSSCREENPRESENTER_HPP
#define SENSORSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SensorsScreenView;

class SensorsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SensorsScreenPresenter(SensorsScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SensorsScreenPresenter() {}

    int getTemperature() const;
    unsigned getTemperatureFloat() const;

    int getHumidity() const;
    unsigned getHumidityFloat() const;

    int getPressure() const;
    unsigned getPressureFloat() const;

private:
    SensorsScreenPresenter();

    SensorsScreenView& view;
};

#endif // SENSORSSCREENPRESENTER_HPP
