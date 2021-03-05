#include "Command.h"
#include "Parts.h"

class RelayOnCommand : public Command
{
    public:
        Relay *relay;

        RelayOnCommand(Relay *relay)
        {
            this->relay = relay;
        }

        void Excute()
        {
            relay->On();
        }

};

class RelayOffCommand : public Command
{
    public:
        Relay *relay;

        RelayOffCommand(Relay *relay)
        {
            this->relay = relay;
        }

        void Excute()
        {
            relay->Off();
        }
};

class MotorOnCommand : public Command 
{
    public:
        Motor *motor;

        MotorOnCommand(Motor *motor)
        {
            this->motor = motor;
        }

        void Excute()
        {
            motor->On();
        }
};

class MotorOffCommand : public Command
{
    public:
        Motor *motor;

        MotorOffCommand(Motor *motor)
        {
            this->motor = motor;
        }

        void Excute()
        {
            motor->Off();
        }
};

class ClutchOnCommand : public Command
{
    public:
        Clutch *clutch;

        ClutchOnCommand(Clutch *clutch)
        {
            this->clutch = clutch;
        }

        void Excute()
        {
            clutch->On();
        }
};

class ClutchOffCommand : public Command
{
    public:
        Clutch *clutch;

        ClutchOffCommand(Clutch *clutch)
        {
            this->clutch = clutch;
        }

        void Excute()
        {
            clutch->Off();
        }
};

int main()
{
    Relay *relay = new Relay;
    Motor *motor = new Motor;
    Clutch *clutch = new Clutch;

    Command *relayOn = new RelayOnCommand(relay);
    Command *relayOff = new RelayOffCommand(relay);

    Command *motorOn = new MotorOnCommand(motor);
    Command *motorOff = new MotorOffCommand(motor);

    Command *clutchOn = new ClutchOnCommand(clutch);
    Command *clutchOff = new ClutchOffCommand(clutch);

    relayOn->Excute();
    relayOff->Excute();

    motorOn->Excute();
    motorOff->Excute();

    clutchOn->Excute();
    clutchOff->Excute();

    delete(relayOn);
    delete(relayOff);

    delete(motorOn);
    delete(motorOff);

    delete(clutchOn);
    delete(clutchOff);

    return 0;
}
