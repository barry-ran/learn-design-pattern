#pragma once
#include "IDoor.h"
#include <iostream>
#include <string>
class IronDoor : public IDoor
{
public:        
    void getDescription() override
    {
        std::cout << "this is IronDoor" << std::endl;
    }
};