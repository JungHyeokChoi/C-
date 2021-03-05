#include "ActiveObjectEngine.h"

using namespace std;

void ActiveObjectEngine :: AddCommand(Command *c)
{
    itsCommand.push_back(c);
};

void ActiveObjectEngine :: Run() throw()
{
    while(!itsCommand.empty()) {
        list<Command*> :: iterator iter = itsCommand.begin();
        Command* c = *iter;
        itsCommand.pop_front();
        c->Execute();
    }
};