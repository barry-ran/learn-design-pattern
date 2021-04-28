#pragma once

#include <iostream>

class MeetingContext;
class MeetingState
{
public:
    virtual ~MeetingState() {}

    virtual void startMeeting(MeetingContext* context) = 0;
    virtual void stopMeeting(MeetingContext* context) = 0;
    virtual void openPreview(MeetingContext* context) = 0;
    virtual void invite(MeetingContext* context) = 0;
};