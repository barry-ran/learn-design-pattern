#pragma once
#include <string>
class IDoor;
class IDoorFactory
{
public:
    virtual ~IDoorFactory() {}    
    virtual IDoor *createDoor() = 0;
    
};
