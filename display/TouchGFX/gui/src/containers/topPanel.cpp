#include <gui/containers/topPanel.hpp>

topPanel::topPanel()
{

}

void topPanel::initialize()
{
    topPanelBase::initialize();
}

void topPanel::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    time.setTime24Hour(hour, minute, second);
}
