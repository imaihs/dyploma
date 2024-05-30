#ifndef TIMESETTINGSSCREENVIEW_HPP
#define TIMESETTINGSSCREENVIEW_HPP

#include <gui_generated/timesettingsscreen_screen/TimeSettingsScreenViewBase.hpp>
#include <gui/timesettingsscreen_screen/TimeSettingsScreenPresenter.hpp>

class TimeSettingsScreenView : public TimeSettingsScreenViewBase
{
public:
    TimeSettingsScreenView();
    virtual ~TimeSettingsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void updateTime(unsigned hour, unsigned minute, unsigned second);
    void peekTime(unsigned hour, unsigned minute, unsigned second);
    void peekDate(unsigned week, unsigned day, unsigned month, unsigned year);

    void UpHourClicked();
    void UpMinuteClicked();
    void UpSecondClicked();
    void DownHourClicked();
    void DownMinuteClicked();
    void DownSecondClicked();
    void SaveTimeClicked();

    void UpDayClicked();
    void UpMonthClicked();
    void UpYearClicked();
    void DownDayClicked();
    void DownMonthClicked();
    void DownYearClicked();
    void SaveDateClicked();
protected:
    unsigned week;
    unsigned day;
    unsigned month;
    unsigned year;
};

#endif // TIMESETTINGSSCREENVIEW_HPP
