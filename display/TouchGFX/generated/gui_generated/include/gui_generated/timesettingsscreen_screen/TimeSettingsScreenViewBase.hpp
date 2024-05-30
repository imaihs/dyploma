/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMESETTINGSSCREENVIEWBASE_HPP
#define TIMESETTINGSSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/timesettingsscreen_screen/TimeSettingsScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>
#include <gui/containers/topPanel.hpp>

class TimeSettingsScreenViewBase : public touchgfx::View<TimeSettingsScreenPresenter>
{
public:
    TimeSettingsScreenViewBase();
    virtual ~TimeSettingsScreenViewBase();
    virtual void setupScreen();

    /*
     * Virtual Action Handlers
     */
    virtual void UpHourClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void UpMinuteClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void UpSecondClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void DownHourClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void DownMinuteClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void DownSecondClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void SaveTimeClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void UpDayClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void UpMonthClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void UpYearClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void DownDayClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void DownMonthClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void DownYearClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }
    virtual void SaveDateClicked()
    {
        // Override and implement this function in TimeSettingsScreen
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::TextAreaWithOneWildcard date;
    touchgfx::TextButtonStyle< touchgfx::ClickButtonTrigger >  save_date_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  down_year_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  down_month_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  down_day_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  up_year_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  up_month_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  up_day_button;
    touchgfx::TextButtonStyle< touchgfx::ClickButtonTrigger >  save_time_button;
    touchgfx::DigitalClock time;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  down_second_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  down_minute_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  down_hour_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  up_second_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  up_minute_button;
    touchgfx::IconButtonStyle< touchgfx::RepeatButtonTrigger >  up_hour_button;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  goBack;
    topPanel topPanel1;

    /*
     * Wildcard Buffers
     */
    static const uint16_t DATE_SIZE = 20;
    touchgfx::Unicode::UnicodeChar dateBuffer[DATE_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<TimeSettingsScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // TIMESETTINGSSCREENVIEWBASE_HPP
