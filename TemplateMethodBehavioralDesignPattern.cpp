// TemplateMethodBehavioralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Step 1: Template Method (Abstract Class)
class VehicleTemplate
{
public:
    // Template method defines the algorithm structure
    void buildVehicle()
    {
        assembleBody();
        installEngine();
        addWheels();
        std::cout << "Vehicle is ready!\n";
    }

    // Abstract methods to be implemented by concrete classes
    virtual void assembleBody() = 0;
    virtual void installEngine() = 0;
    virtual void addWheels() = 0;
};

// Step 2: Concrete Classes - Car and Motorcycle
class Car : public VehicleTemplate
{
public:
    void assembleBody() override
    {
        std::cout << "Assembling Car body.\n";
    }
    void installEngine() override
    {
        std::cout << "Installing Car Engine.\n";
    }
    void addWheels() override
    {
        std::cout << "Adding four wheels to the Car.\n";
    }

};

class MotorCycle : public VehicleTemplate
{
public:
    void assembleBody() override
    {
        std::cout << "Assembling MotorCycle body.\n";
    }
    void installEngine() override
    {
        std::cout << "Installing MotorCycle Engine.\n";
    }
    void addWheels() override
    {
        std::cout << "Adding two wheels to the MotorCycle.\n";
    }
};
// Step 3: Client Code
int main()
{
    std::cout << "Building a car:\n";
    Car car;
    car.buildVehicle();
    std::cout << '\n';

    std::cout << "Building a MotorCycle:\n";
    MotorCycle bike;
    bike.buildVehicle();

    return 0;
}

