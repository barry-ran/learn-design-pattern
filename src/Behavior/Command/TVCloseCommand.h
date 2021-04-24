#pragma once
#include "TVReceiver.h"
#include "ICommand.h"
class TVCloseCommand : public ICommand
{
public:
    TVCloseCommand(TVReceiver *tvReceiver):m_tvReceiver(tvReceiver) {}
    
    virtual void execute() override
    {
        m_tvReceiver->off();
    }

private:
    TVReceiver *m_tvReceiver;
};