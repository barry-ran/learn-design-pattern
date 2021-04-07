#pragma once
#include "IDisplay.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
class StringDisplay : public IDisplay
{
public:
    StringDisplay(const std::string &str) : m_str(str) {}
    void open() override
    {
        cout << "open StringDisplay" << endl;
    }
    void close() override
    {
        cout << "close StringDisplay" << endl;
    }
    void print() override
    {
        cout << "StringDisplay print:" << m_str << endl;
    }

private:
    std::string m_str;
};
