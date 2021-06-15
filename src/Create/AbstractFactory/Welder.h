#pragma once
#include "IDoorFittingExpert.h"
#include <iostream>
#include <string>

class Welder : public IDoorFittingExpert
{
public:        
    void getAbility() override
    {
        std::cout << "i am Welder, i can fit IronDoor" << std::endl;
    }
};