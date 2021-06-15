#pragma once
#include <string>
class IDoor;
class IDoorFittingExpert;
class IDoorFactory
{
public:
    virtual ~IDoorFactory() {}    
    virtual IDoor* createDoor() = 0;
    virtual IDoorFittingExpert* createDoorFittingExpert() = 0;
    
};
