#ifndef COMMAND_H
#define COMMAND_H

class Command{
    public:
        virtual ~Command() {}
        virtual void excute() = 0;
};

#endif