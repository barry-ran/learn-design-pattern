#pragma once
#include <string>
#include "IColor.h"
class IShape
{
public:
    virtual ~IShape() {}
    IShape(IColor *color) : m_color(color) {}
    
    virtual std::string getName() = 0;

protected:
    IColor *m_color;
};