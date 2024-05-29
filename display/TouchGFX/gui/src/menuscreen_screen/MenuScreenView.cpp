#include <gui/menuscreen_screen/MenuScreenView.hpp>

MenuScreenView::MenuScreenView()
{

}

void MenuScreenView::setupScreen()
{
    MenuScreenViewBase::setupScreen();
    presenter->UIGetTime();
}

void MenuScreenView::tearDownScreen()
{
    MenuScreenViewBase::tearDownScreen();
}

void MenuScreenView::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    topPanel1.updateTime(hour, minute, second);
}