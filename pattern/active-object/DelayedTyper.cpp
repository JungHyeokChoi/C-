#include <iostream>

#include "Command.h"
#include "ActiveObjectEngine.h"
#include "SleepCommand.h"

using namespace std;

ActiveObjectEngine *engine;
static bool stop;

class DelayedTyper : public Command
{
    private:
        long itsDelay;
        char itsChar;
    public:
        DelayedTyper(long delay, char c) {
            itsDelay = delay;
            itsChar = c;
        }
        void Execute() throw() {
            cout << itsChar << endl;
            if(!stop) delayAndRepeat();
        };

        void delayAndRepeat() throw() {
            engine->AddCommand(new SleepCommand(itsDelay, engine, this));
        };
};

class StopCommand : public Command
{
    public:
        void Execute() throw() {
            stop = true;
        };
};

int main(int argv, char* argc[]) 
{
    engine = new ActiveObjectEngine();
    stop = false;

    engine->AddCommand(new DelayedTyper(100, '1'));
    engine->AddCommand(new DelayedTyper(300, '3'));
    engine->AddCommand(new DelayedTyper(500, '5'));
    engine->AddCommand(new DelayedTyper(700, '7'));

    StopCommand *stopCommand = new StopCommand();

    engine->AddCommand(new SleepCommand(20000, engine, stopCommand));
    engine->Run();
}