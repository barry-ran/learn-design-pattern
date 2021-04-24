#pragma once
#include <iostream>

class TVReceiver
{
public:
    void on()
    {
        std::cout << "tv on" << std::endl;
    }

    void off()
    {
        std::cout << "tv off" << std::endl;
    }
};