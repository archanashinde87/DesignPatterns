#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Target
class Target
{
public:
    virtual ~Target()=default;
    virtual std::string Request() const
    {
        return "Target: The default target's behavior.";
    }
};

// Adaptee
class Adaptee
{
public:
    std::string specificRequest() const
    {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// Adapter
class Adapter : public Target, public Adaptee
{
public:
    Adapter(){}
    
    std::string Request() const override
    {
        std::string to_reverse = specificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter(Translated) :" + to_reverse; 
    }
};

void clientCode(const Target* target)
{
   std::cout << target->Request(); 
}

int main()
{
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target();
    clientCode(target);
    std::cout << "\n\n";
    
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    Adaptee* adaptee = new Adaptee();
    std::cout << "Adaptee: " << adaptee->specificRequest();
    std::cout << "\n\n";

    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter* adapter = new Adapter();
    clientCode(adapter);
    std::cout << "\n\n";
    
    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}