#ifndef SLEEPCOMMAND_H
#define SLEEPCOMMAND_H

#include "ActiveObjectEngine.h"

class SleepCommand : public Command
{
    private:
        Command *wakeUpCommand;
        ActiveObjectEngine *engine;
        long sleepTime;
        long startTime;
        bool started;

    public:
        SleepCommand(long milliseconds, ActiveObjectEngine *e, Command *wakeUpCommand) {
            sleepTime = milliseconds;
            engine = e;
            this->wakeUpCommand = wakeUpCommand;
        }
        virtual ~SleepCommand() {}
        void Execute() throw();
};

#endif