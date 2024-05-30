#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateTime(unsigned hour, unsigned minute, unsigned second) {}
    virtual void peekTime(unsigned hour, unsigned minute, unsigned second) {}
    virtual void updateDate(unsigned week, unsigned day, unsigned month, unsigned year) {}
    virtual void peekDate(unsigned week, unsigned day, unsigned month, unsigned year) {}

protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
