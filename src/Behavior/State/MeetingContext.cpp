#include "MeetingContext.h"
#include "FreeState.h"

MeetingContext::MeetingContext(): m_state(FreeState::getInstance()) {}

void MeetingContext::startMeeting() {
    m_state->startMeeting(this);
}

void MeetingContext::stopMeeting() {
    m_state->stopMeeting(this);
}

void MeetingContext::openPreview() {
    m_state->openPreview(this);
}

void MeetingContext::invite() {
    m_state->invite(this);
}

void MeetingContext::changeState(MeetingState* state) {
    m_state = state;
}    