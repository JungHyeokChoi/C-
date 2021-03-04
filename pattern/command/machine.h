#ifndef MACHINE_H
#define MACHINE_H

class Relay {
    public:
        void On();
        void Off();
};

class Motor {
    public:
        void On();
        void Off();
};

class Clutch {
    public:
        void On();
        void Off();
};

#endif