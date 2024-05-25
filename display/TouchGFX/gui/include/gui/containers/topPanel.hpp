#ifndef TOPPANEL_HPP
#define TOPPANEL_HPP

#include <gui_generated/containers/topPanelBase.hpp>

class topPanel : public topPanelBase
{
public:
    topPanel();
    virtual ~topPanel() {}

    virtual void initialize();
protected:
};

#endif // TOPPANEL_HPP
