#ifndef ACTIVEOBJECT_H
#define ACTIVEOBJECT_H

#include <iostream>
#include <list>

#include "Command.h"

using namespace std;

class ActiveObjectEngine
{
    public:
        virtual void AddCommand() = 0;
        virtual void Run() throw(Exception) = 0;

    private:
        list<Commnad> itsCommand;
}

#endif