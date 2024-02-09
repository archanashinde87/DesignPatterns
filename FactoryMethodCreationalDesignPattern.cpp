/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

class Product
{
public:
    virtual ~Product() {}
    virtual std::string operation() const = 0;
};

class ConcreteProduct1 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product
{
public:
    std::string operation() const override
    {
        return "{Result of the ConcreteProduct2}";
    }
};

class Creator
{
public:
    virtual ~Creator(){}
    virtual Product* FactoryMethod() const = 0;
    std::string someOperation() const
    {
        Product* product = this->FactoryMethod();
        std::string result = "Creator: The same creator's code has just worked with " + product->operation();
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator
{
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{
public:
    Product* FactoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};

void clientCode(const Creator& creator)
{
      std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
                << creator.someOperation() << std::endl;
}

int main()
{
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator1 = new ConcreteCreator1();
    clientCode(*creator1);
    std::cout << std::endl;
 
    std::cout << "App: Launched with the ConcreteCreator2.\n";   
    Creator* creator2 = new ConcreteCreator2();
    clientCode(*creator2);
    std::cout << std::endl;
    
    delete creator1;
    delete creator2;
    
    return 0;
}
