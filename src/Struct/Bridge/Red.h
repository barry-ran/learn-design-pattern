#pragma once
#include "IColor.h"

class Red : public IColor
{
public:
    std::string getColor() {
        return "red";
    }
};