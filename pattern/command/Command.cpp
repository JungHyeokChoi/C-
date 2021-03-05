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

        void Execute()
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

        void Execute()
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

        void Execute()
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

        void Execute()
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

        void Execute()
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

        void Execute()
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

    relayOn->Execute();
    relayOff->Execute();

    motorOn->Execute();
    motorOff->Execute();

    clutchOn->Execute();
    clutchOff->Execute();

    delete(relayOn);
    delete(relayOff);

    delete(motorOn);
    delete(motorOff);

    delete(clutchOn);
    delete(clutchOff);

    return 0;
}
