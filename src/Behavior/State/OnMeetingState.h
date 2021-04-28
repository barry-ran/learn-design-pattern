#pragma once
#include <iostream>

#include "MeetingState.h"
#include "MeetingContext.h"

class OnMeetingState : public MeetingState
{
public:
    ~OnMeetingState() {}

	static OnMeetingState* getInstance();

    void startMeeting(MeetingContext* context) override;    
    void stopMeeting(MeetingContext* context) override;
    void openPreview(MeetingContext* context) override;
    void invite(MeetingContext* context) override;
};