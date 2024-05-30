#include <gui/homescreen_screen/HomeScreenView.hpp>
#include <touchgfx\Unicode.hpp>

HomeScreenView::HomeScreenView()
{

}

void HomeScreenView::setupScreen()
{
    HomeScreenViewBase::setupScreen();
    presenter->UIGetTime();
    presenter->UIGetDate();
}

void HomeScreenView::tearDownScreen()
{
    HomeScreenViewBase::tearDownScreen();
}

void HomeScreenView::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    time.setTime24Hour(hour, minute, second);
}

void HomeScreenView::updateDate(unsigned week, unsigned day, unsigned month, unsigned year)
{
    Unicode::UnicodeChar weekday_text[7][16];
    Unicode::fromUTF8((const uint8_t *) "Monday\0", weekday_text[0], 16);
    Unicode::fromUTF8((const uint8_t *) "Tuesday\0", weekday_text[1], 16);
    Unicode::fromUTF8((const uint8_t *) "Wednesday\0", weekday_text[2], 16);
    Unicode::fromUTF8((const uint8_t *) "Thursday\0", weekday_text[3], 16);
    Unicode::fromUTF8((const uint8_t *) "Friday\0", weekday_text[4], 16);
    Unicode::fromUTF8((const uint8_t *) "Saturday\0", weekday_text[5], 16);
    Unicode::fromUTF8((const uint8_t *) "Sunday\0", weekday_text[6], 16);
    Unicode::snprintf(dateBuffer, DATE_SIZE, "%s, %02u.%02u.%02u", weekday_text[week-1], day, month, year);
    date.invalidate();
}