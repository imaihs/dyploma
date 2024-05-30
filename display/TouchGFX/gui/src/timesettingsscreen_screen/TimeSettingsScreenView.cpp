#include <gui/timesettingsscreen_screen/TimeSettingsScreenView.hpp>

static unsigned get_max_day(unsigned month, unsigned year) {
    bool is_leap = 0;
    unsigned max_day = 0;
    if(year % 4 == 0) {
        is_leap = 1;
    }

    if(month == 2) {
        if(is_leap) {
            max_day = 29;
        } else {
            max_day = 28;
        }
    }
    else if(month == 4 || month == 6 || month == 9 || month == 11) {
        max_day = 30;
    } else {
        max_day = 31;
    }
    return max_day;
}

TimeSettingsScreenView::TimeSettingsScreenView() : week(0), day(0), month(0), year(0)
{

}

void TimeSettingsScreenView::setupScreen()
{
    TimeSettingsScreenViewBase::setupScreen();
    presenter->UIGetTime();
    presenter->UIGetDate();
}

void TimeSettingsScreenView::tearDownScreen()
{
    TimeSettingsScreenViewBase::tearDownScreen();
}

void TimeSettingsScreenView::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    topPanel1.updateTime(hour, minute, second);
}

void TimeSettingsScreenView::peekTime(unsigned hour, unsigned minute, unsigned second)
{
    time.setTime24Hour(hour, minute, second);
}

void TimeSettingsScreenView::peekDate(unsigned week, unsigned day, unsigned month, unsigned year)
{
    this->week = week;
    this->day = day;
    this->month = month;
    this->year = year;
    Unicode::snprintf(dateBuffer, DATE_SIZE, "%02u.%02u.%02u", day, month, year);
    date.invalidate();
}

void TimeSettingsScreenView::UpHourClicked() {
    time.setTime24Hour(time.getCurrentHour24() + 1, time.getCurrentMinute(), time.getCurrentSecond());
}

void TimeSettingsScreenView::UpMinuteClicked() {
    time.setTime24Hour(time.getCurrentHour24(), time.getCurrentMinute() + 1, time.getCurrentSecond());
}

void TimeSettingsScreenView::UpSecondClicked() {
    time.setTime24Hour(time.getCurrentHour24(), time.getCurrentMinute(), time.getCurrentSecond() + 1);
}

void TimeSettingsScreenView::DownHourClicked() {
    time.setTime24Hour(time.getCurrentHour24() + 23, time.getCurrentMinute(), time.getCurrentSecond());
}

void TimeSettingsScreenView::DownMinuteClicked() {
    time.setTime24Hour(time.getCurrentHour24(), time.getCurrentMinute() + 59, time.getCurrentSecond());
}

void TimeSettingsScreenView::DownSecondClicked() {
    time.setTime24Hour(time.getCurrentHour24(), time.getCurrentMinute(), time.getCurrentSecond() + 59);
}

void TimeSettingsScreenView::SaveTimeClicked() {
    presenter->UISetTime(time.getCurrentHour24(), time.getCurrentMinute(), time.getCurrentSecond());
    presenter->UIGetTime();
}

void TimeSettingsScreenView::UpDayClicked()
{
    if(++day > get_max_day(month, year)) {
        day = 1;
    }

    Unicode::snprintf(dateBuffer, DATE_SIZE, "%02u.%02u.%02u", day, month, year);
    date.invalidate();
}

void TimeSettingsScreenView::UpMonthClicked()
{
    month = month % 12 + 1;
    day = day > get_max_day(month, year) ? get_max_day(month, year) : day;
    Unicode::snprintf(dateBuffer, DATE_SIZE, "%02u.%02u.%02u", day, month, year);
    date.invalidate();
}

void TimeSettingsScreenView::UpYearClicked()
{
    year = (year + 1) % 100;
    day = day > get_max_day(month, year) ? get_max_day(month, year) : day;
    Unicode::snprintf(dateBuffer, DATE_SIZE, "%02u.%02u.%02u", day, month, year);
    date.invalidate();
}

void TimeSettingsScreenView::DownDayClicked()
{
    if(--day == 0) {
        day = get_max_day(month, year);
    }

    Unicode::snprintf(dateBuffer, DATE_SIZE, "%02u.%02u.%02u", day, month, year);
    date.invalidate();
}

void TimeSettingsScreenView::DownMonthClicked()
{
    month = (month + 10) % 12 + 1;
    day = day > get_max_day(month, year) ? get_max_day(month, year) : day;
    Unicode::snprintf(dateBuffer, DATE_SIZE, "%02u.%02u.%02u", day, month, year);
    date.invalidate();
}

void TimeSettingsScreenView::DownYearClicked()
{
    year = (year + 99) % 100;
    day = day > get_max_day(month, year) ? get_max_day(month, year) : day;
    Unicode::snprintf(dateBuffer, DATE_SIZE, "%02u.%02u.%02u", day, month, year);
    date.invalidate();
}

void TimeSettingsScreenView::SaveDateClicked()
{
    presenter->UISetDate(day, month, year);
}
