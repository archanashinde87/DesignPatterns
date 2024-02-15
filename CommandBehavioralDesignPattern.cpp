// CommandBehavioralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

// Receiver : Electronic Device
class ElectronicDevice
{
    std::string m_name{};
public:
    ElectronicDevice(const std::string& name)
        : m_name{ name }
    {}
    void turnOn()
    {
        std::cout << m_name << " is now ON.\n";
    }
    void turnOff()
    {
        std::cout << m_name << " is now OFF.\n";
    }
};
// Abstract Class  for Command (Command Interface)
class Command
{
public:
    virtual void execute() = 0;
};
// Concrete Command
class TurnOnCommand : public Command
{
private:
    ElectronicDevice& m_eDevice;
public:
    TurnOnCommand(ElectronicDevice& eDevice) :m_eDevice{ eDevice } {}
    void execute() override
    {
        m_eDevice.turnOn();
    }
};
// Concrete Command 
class TurnOffCommand : public Command
{
private:
    ElectronicDevice& m_ElectronicDevive;
public:
    TurnOffCommand(ElectronicDevice& eDevice) :m_ElectronicDevive{ eDevice } {}
    void execute() override
    {
        m_ElectronicDevive.turnOff();
    }
};
// Invoker
class RemoteControl
{
private:
    std::vector<Command*> m_Commands;
public:
    void addCommand(Command* cmd)
    {
        m_Commands.push_back(cmd);
    }
    void pressButton(int slot)
    {
        if (slot >= 0 && slot < m_Commands.size())
            m_Commands[slot]->execute();
    }
};
int main()
{
    // Create electronic devices
    ElectronicDevice tv{ "TV" };
    ElectronicDevice lights{"Light"};

    // Create commands for turning devices on and off
    TurnOnCommand turnONTV{tv};
    TurnOffCommand turnOffTV{ tv };
    TurnOnCommand turnONLights{ lights };
    TurnOffCommand turnOffLights{ lights };

    // Create a remote control
    RemoteControl remote;
    // Set commands for remote buttons
    remote.addCommand(&turnONTV); // Button 0: Turn on TV
    remote.addCommand(&turnOffTV); // Button 1: Turn off TV
    remote.addCommand(&turnONLights); // Button 2: Turn on Lights
    remote.addCommand(&turnOffLights); // Button 3: Turn off Lights

    // Press buttons on the remote
    remote.pressButton(0); // Turn on TV
    remote.pressButton(3); // Turn off lights
    remote.pressButton(1); // Turn off TV
    remote.pressButton(2); // turn on lights

    return 0;
}

