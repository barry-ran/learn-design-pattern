#pragma once
#include <iostream>

#include "MeetingState.h"
#include "MeetingContext.h"

class FreeState : public MeetingState
{
public:
    ~FreeState() {}

    static FreeState* getInstance();

    void startMeeting(MeetingContext* context) override;    
    void stopMeeting(MeetingContext* context) override;
    void openPreview(MeetingContext* context) override;
    void invite(MeetingContext* context) override;
};