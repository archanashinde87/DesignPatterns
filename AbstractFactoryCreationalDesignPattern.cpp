/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

class AbstractProductA
{
public:
    virtual ~AbstractProductA(){}
    virtual std::string UsefulFunctionA() const = 0;
};
class ConcreteProductA1 : public AbstractProductA
{
public:
    ~ConcreteProductA1(){}
    std::string UsefulFunctionA() const override
    {
        return "The result of the product A1.";
    }
};
class ConcreteProductA2 : public AbstractProductA
{
public:
    ~ConcreteProductA2(){}
    std::string UsefulFunctionA() const override
    {
        return "The result of the product A2.";
    }
};

class AbstractProductB
{
public:
    virtual ~AbstractProductB(){}
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};
class ConcreteProductB1 : public AbstractProductB
{
public:
    ~ConcreteProductB1(){}
    std::string UsefulFunctionB() const override
    {
        return "The result of the product B1.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override
    {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};
class ConcreteProductB2 : public AbstractProductB
{
public:
    ~ConcreteProductB2(){}
    std::string UsefulFunctionB() const override
    {
        return "The result of the product B2.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override
    {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

class AbstractFactory
{
public:
    virtual ~AbstractFactory(){}
    virtual AbstractProductA* createProductA() const = 0;
    virtual AbstractProductB* createProductB() const = 0;
};
class ConcreteFactory1 : public AbstractFactory
{
public:
    ~ConcreteFactory1(){}
    AbstractProductA* createProductA() const override
    {
        return new ConcreteProductA1();
    }
    AbstractProductB* createProductB() const override
    {
        return new ConcreteProductB1();
    }
};
class ConcreteFactory2 : public AbstractFactory
{
public:
    ~ConcreteFactory2() {}
    AbstractProductA* createProductA() const override
    {
        return new ConcreteProductA2();
    }
    AbstractProductB* createProductB() const override
    {
        return new ConcreteProductB2();
    }
};

void clientCode(const AbstractFactory& factory)
{
    const AbstractProductA* product_A = factory.createProductA();
    const AbstractProductB* product_B =factory.createProductB();
    
    std::cout << product_B->UsefulFunctionB() << "\n";
    std::cout << product_B->AnotherUsefulFunctionB(*product_A) <<"\n";
    delete product_A;
    delete product_B;
}

int main()
{
    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1* concretefactory1 = new ConcreteFactory1();
    clientCode(*concretefactory1);
    delete concretefactory1;
    std::cout << std::endl;
    
    std::cout << "Client: Testing client code with the second factory type:\n";
    ConcreteFactory2* concretefactory2 = new ConcreteFactory2();
    clientCode(*concretefactory2);
    delete concretefactory2;
    std::cout << std::endl;

    return 0;
}
