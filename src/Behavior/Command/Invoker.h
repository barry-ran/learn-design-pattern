#pragma once
#include "ICommand.h"

class Invoker
{
public:
    Invoker(ICommand* commond):m_commond(commond) {}

    void setCommand(ICommand* commond) {
        m_commond = commond;
    }

    void call()
    {
        m_commond->execute();
    }

private:
    ICommand* m_commond = nullptr;
};