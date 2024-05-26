#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <gui_generated/containers/settingsBase.hpp>

class settings : public settingsBase
{
public:
    settings();
    virtual ~settings() {}

    virtual void initialize();
protected:
};

#endif // SETTINGS_HPP
