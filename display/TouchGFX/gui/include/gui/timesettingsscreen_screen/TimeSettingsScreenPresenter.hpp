#ifndef TIMESETTINGSSCREENPRESENTER_HPP
#define TIMESETTINGSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class TimeSettingsScreenView;

class TimeSettingsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    TimeSettingsScreenPresenter(TimeSettingsScreenView& v);

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

    virtual ~TimeSettingsScreenPresenter() {}

    void updateTime(unsigned hour, unsigned minute, unsigned second);
    void peekTime(unsigned hour, unsigned minute, unsigned second);
    void UIGetTime(void);
    void UISetTime(unsigned hour, unsigned minute, unsigned second);

    void peekDate(unsigned week, unsigned day, unsigned month, unsigned year);
    void UIGetDate(void);
    void UISetDate(unsigned day, unsigned month, unsigned year);

private:
    TimeSettingsScreenPresenter();

    TimeSettingsScreenView& view;
};

#endif // TIMESETTINGSSCREENPRESENTER_HPP
