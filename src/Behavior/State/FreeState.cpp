
#include "FreeState.h"
#include "OnMeetingState.h"

FreeState* FreeState::getInstance()
{
	static FreeState s;
	return &s;
}

void FreeState::startMeeting(MeetingContext* context)
{
	std::cout << "startMeeting success" << std::endl;
	context->changeState(OnMeetingState::getInstance());
}

void FreeState::stopMeeting(MeetingContext* context)
{
	std::cout << "ont in meeting, stopMeeting invalid" << std::endl;
}

void FreeState::openPreview(MeetingContext* context)
{
	std::cout << "openPreview success" << std::endl;
}

void FreeState::invite(MeetingContext* context)
{
	std::cout << "ont in meeting, invite faild" << std::endl;
}

