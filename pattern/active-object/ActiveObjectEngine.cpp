#include "ActiveObjectEngine.h"

void ActiveObjectEngine :: AddCommand(Command c)
{
    itsCommand.add(c)
} 

void ActiveObjectEngine :: Run() throw(Exception)
{
    while(!itsCommand.empty()) {
        Command c = (Command) itsCommand.begin();
        itsCommand.pop_front();
        c.excute();
    }
}