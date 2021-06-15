#pragma once
#include "WoodenDoor.h"
#include "IDoorFactory.h"
#include "Carpenter.h"
#include <string>
class WoodenDoorFactory : public IDoorFactory
{
public:
    IDoor *createDoor()
    {
        return new WoodenDoor();
    }

    IDoorFittingExpert* createDoorFittingExpert()  {
        return new Carpenter();
    }
};