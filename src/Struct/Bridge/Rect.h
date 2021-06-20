#pragma once
#include "IShape.h"
class Rect : public IShape
{
public:
    Rect(IColor *color):IShape(color){}
    std::string getName() {
        return m_color->getColor() + "+rect";
    }
};