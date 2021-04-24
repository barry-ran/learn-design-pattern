#pragma once
#include "TVReceiver.h"
#include "ICommand.h"
class TVOpenCommand : public ICommand
{
public:
    TVOpenCommand(TVReceiver *tvReceiver):m_tvReceiver(tvReceiver) {}
    
    virtual void execute() override
    {
        m_tvReceiver->on();
    }

private:
    TVReceiver *m_tvReceiver;
};