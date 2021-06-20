#pragma once
#include <string>
class IColor
{
public:
    virtual ~IColor() {}
    virtual std::string getColor() = 0;
};