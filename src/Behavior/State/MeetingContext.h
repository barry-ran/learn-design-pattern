#pragma once

#pragma once
#include "MeetingState.h"

class MeetingContext
{
public:
    MeetingContext();
    void startMeeting();
    void stopMeeting();
    void openPreview();
    void invite();
    void changeState(MeetingState* state);

private:
    MeetingState* m_state = nullptr;
};