#ifndef HOME_HPP
#define HOME_HPP

#include <gui_generated/containers/homeBase.hpp>

class home : public homeBase
{
public:
    home();
    virtual ~home() {}

    virtual void initialize();
protected:
};

#endif // HOME_HPP
