#include "MeetingContext.h"

int main() {
    MeetingContext context;
    context.openPreview();
    context.startMeeting();
    context.openPreview();
    context.invite();
    context.stopMeeting();
    context.invite();
    return 0;
}