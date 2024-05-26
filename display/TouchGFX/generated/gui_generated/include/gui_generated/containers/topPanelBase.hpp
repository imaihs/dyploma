/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TOPPANELBASE_HPP
#define TOPPANELBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/Image.hpp>

class topPanelBase : public touchgfx::Container
{
public:
    topPanelBase();
    virtual ~topPanelBase();
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box box1;
    touchgfx::TextAreaWithTwoWildcards time;
    touchgfx::Image ok;
    touchgfx::Image warning;
    touchgfx::Image conn1;
    touchgfx::Image conn2;
    touchgfx::Image conn3;
    touchgfx::Image conn4;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TIMEBUFFER1_SIZE = 4;
    touchgfx::Unicode::UnicodeChar timeBuffer1[TIMEBUFFER1_SIZE];
    static const uint16_t TIMEBUFFER2_SIZE = 4;
    touchgfx::Unicode::UnicodeChar timeBuffer2[TIMEBUFFER2_SIZE];

private:

};

#endif // TOPPANELBASE_HPP
