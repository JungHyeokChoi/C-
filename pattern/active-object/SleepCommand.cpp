#include <chrono>
#include <ctime>
#include <sys/time.h>

#include "SleepCommand.h"

void SleepCommand :: Execute() throw()
{
    time_t currentTime = time(nullptr) * 1000;
    if(!started) {
        started = true;
        startTime = currentTime;
        engine->AddCommand(this);
    } else if ((currentTime - startTime) < sleepTime) {
        engine->AddCommand(this);
    } else {
        engine->AddCommand(wakeUpCommand);
    }
}