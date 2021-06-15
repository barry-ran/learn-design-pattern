#pragma once
#include "IDoorFittingExpert.h"
#include <iostream>
#include <string>

class Carpenter : public IDoorFittingExpert
{
public:        
    void getAbility() override
    {
        std::cout << "i am Carpenter, i can fit WoodenDoor" << std::endl;
    }
};