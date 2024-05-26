#include <gui/menuscreen_screen/MenuScreenView.hpp>
#include <gui_generated\containers\homeBase.hpp>

MenuScreenView::MenuScreenView() :
        homeClickedCallback(this, &MenuScreenView::homeClickHandler),
        sensorsClickedCallback(this, &MenuScreenView::sensorsClickHandler),
        eventsClickedCallback(this, &MenuScreenView::eventsClickHandler),
        settingsClickedCallback(this, &MenuScreenView::settingsClickHandler)
{

}

void MenuScreenView::setupScreen()
{
    homeButton.setClickAction(homeClickedCallback);
    sensorsButton.setClickAction(sensorsClickedCallback);
    eventsButton.setClickAction(eventsClickedCallback);
    settingsButton.setClickAction(settingsClickedCallback);

    MenuScreenViewBase::setupScreen();
}

void MenuScreenView::tearDownScreen()
{
    MenuScreenViewBase::tearDownScreen();
}

void MenuScreenView::homeClickHandler(const home& h, const ClickEvent& e)
{
    application().gotoHomeScreenScreenNoTransition();
}

void MenuScreenView::sensorsClickHandler(const sensors& h, const ClickEvent& e)
{
    application().gotoSensorsScreenScreenNoTransition();
}

void MenuScreenView::eventsClickHandler(const events& h, const ClickEvent& e)
{
    application().gotoEventsScreenScreenNoTransition();
}

void MenuScreenView::settingsClickHandler(const settings& h, const ClickEvent& e)
{
    application().gotoSettingsScreenScreenNoTransition();
}