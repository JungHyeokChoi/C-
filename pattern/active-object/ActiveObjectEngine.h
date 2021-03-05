#ifndef ACTIVEOBJECTENGINE_H
#define ACTIVEOBJECTENGINE_H

#include <list>

#include "Command.h"

using namespace std;

class ActiveObjectEngine
{
    private:
        list<Command*> itsCommand;

    public:
        virtual void AddCommand(Command *c);
        virtual void Run() throw();

};

#endif