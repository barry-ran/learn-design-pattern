#pragma once
#include "WoodenDoor.h"
#include "IDoorFactory.h"
#include <string>
class WoodenDoorFactory : public IDoorFactory
{
public:
    IDoor *createDoor()
    {
        return new WoodenDoor();
    }
};