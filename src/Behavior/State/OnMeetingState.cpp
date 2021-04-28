#include "OnMeetingState.h"
#include "FreeState.h"

OnMeetingState* OnMeetingState::getInstance() {
	static OnMeetingState s;
	return &s;
}

void OnMeetingState::startMeeting(MeetingContext* context)
{
	std::cout << "already on meeting, startMeeting invalid" << std::endl;
}

void OnMeetingState::stopMeeting(MeetingContext* context)
{
	std::cout << "stopMeeting success" << std::endl;
	context->changeState(FreeState::getInstance());
}

void OnMeetingState::openPreview(MeetingContext* context)
{
	std::cout << "already on meeting, openPreview failed" << std::endl;
}

void OnMeetingState::invite(MeetingContext* context)
{
	std::cout << "invite success" << std::endl;
}
