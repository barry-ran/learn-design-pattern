#pragma once
#include "IDisplay.h"
#include <iostream>
using std::cout;
using std::endl;
class CharDisplay : public IDisplay
{
public:
    CharDisplay(const char& str) : m_char(str) {}
    void open() override
    {
        cout << "open CharDisplay" << endl;
    }
    void close() override
    {
        cout << "close CharDisplay" << endl;
    }
    void print() override
    {
        cout << "CharDisplay print:" << m_char << endl;
    }

private:
    char m_char;
};
