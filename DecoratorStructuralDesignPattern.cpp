#include <iostream>
#include <string>

using namespace std;

// Component Interface - defines the basic ice-cream operations.
class IceCream
{
public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Component - The basic ice-cream class
class VanillaIceCream : public IceCream
{
public:
    string getDescription() const override { return "Vanilla Ice Cream";}
    double cost() const override { return 160.0; }
};

// Decorator - Abstract Class that extends IceCream.
class IceCreamDecorator : public IceCream
{
protected:
    IceCream* m_iceCream{};
public:
    IceCreamDecorator(IceCream* ic):m_iceCream{ic}{}
    string getDescription() const override { return m_iceCream->getDescription();}
    double cost() const override { return m_iceCream->cost(); }
};

// Concrete Decorator - adds chocolate topping.
class ChocolateDecorator : public IceCreamDecorator
{
public:
    ChocolateDecorator(IceCream* ic) 
    : IceCreamDecorator{ic}
    {}
    string getDescription() const override { return m_iceCream->getDescription()+" with Chocolate";}
    double cost() const override { return m_iceCream->cost() + 100.0; }
};
// Concrete Decorator - adds caramel topping.
class CaramelDecorator : public IceCreamDecorator
{
public:
    CaramelDecorator(IceCream* ic) 
    : IceCreamDecorator{ic}
    {}
    string getDescription() const override { return m_iceCream->getDescription()+" with Caramel";}
    double cost() const override { return m_iceCream->cost() + 150.0; }
};

int main()
{
    // Create a vanilla ice cream
    IceCream* vanillaIceCream = new VanillaIceCream();
    std::cout << "Order: " << vanillaIceCream->getDescription() << ", Cost Rs." <<vanillaIceCream->cost() << "\n";
    // Wrap it with ChocolateDecorator
    IceCream* chocolateDecorator = new ChocolateDecorator(vanillaIceCream);
    std::cout << "Order: " << chocolateDecorator->getDescription() << ", Cost Rs." << chocolateDecorator->cost() << "\n";   
    // Wrap it with CaramelDecorator
    IceCream* caramelDecorator = new CaramelDecorator(chocolateDecorator);
    std::cout << "Order: " << caramelDecorator->getDescription() << ", Cost Rs." << caramelDecorator->cost() << "\n";   
    
    return 0;
}