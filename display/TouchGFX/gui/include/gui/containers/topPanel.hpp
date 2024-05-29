#ifndef TOPPANEL_HPP
#define TOPPANEL_HPP

#include <gui_generated/containers/topPanelBase.hpp>

class topPanel : public topPanelBase
{
public:
    topPanel();
    virtual ~topPanel() {}

    virtual void initialize();
    
    void updateTime(unsigned hour, unsigned minute, unsigned second);
protected:
};

#endif // TOPPANEL_HPP
