#ifndef COMMAND_H
#define COMMAND_H

class Command
{
    public:
        virtual ~Command() {}
        virtual void Excute() throw(Exception) = 0;
};

#endif