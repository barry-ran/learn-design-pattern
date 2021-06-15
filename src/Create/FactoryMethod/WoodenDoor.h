#pragma once
#include "IDoor.h"
#include <iostream>
#include <string>
class WoodenDoor : public IDoor
{
public:        
    void getDescription() override
    {
        std::cout << "this is WoodenDoor" << std::endl;
    }
};