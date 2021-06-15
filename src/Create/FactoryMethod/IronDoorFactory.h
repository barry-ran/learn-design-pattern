#pragma once
#include "IronDoor.h"
#include "IDoorFactory.h"
#include <string>
class IronDoorFactory : public IDoorFactory
{
public:
    IDoor *createDoor()
    {
        return new IronDoor();
    }
};