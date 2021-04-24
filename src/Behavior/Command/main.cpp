#include <iostream>
using namespace std;

#include "Invoker.h"
#include "TVOpenCommand.h"
#include "TVCloseCommand.h"
#include "TVReceiver.h"

int main (int argc, char **argv) {
    TVReceiver tvReceiver;
    TVOpenCommand tvOpenCommand(&tvReceiver);
    Invoker invoke(&tvOpenCommand);
    invoke.call();

    TVCloseCommand tvCloseCommand(&tvReceiver);
    invoke.setCommand(&tvCloseCommand);
    invoke.call();
    return 0;
}
