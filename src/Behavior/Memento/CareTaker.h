#pragma once
#include "Memento.h"

class CareTaker
{
public:
    CareTaker() = default;
    void setMemento(const Memento& memento)
    {
        m_memento = memento;
    }
    Memento getMemento()
    {
        return m_memento;
    }

private:
    Memento m_memento = Memento(0);
};