#pragma once

class IDoor
{
public:
    virtual ~IDoor() {}
    virtual void getDescription() = 0;
};
