// MediatorBehavioralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class BaseComponent;
// Mediator Interface 
class Mediator
{
public:
    virtual void notify(BaseComponent* sender, std::string event) const = 0;
};

//The Base Component provides the basic functionality of storing a mediator's instance inside component objects.
class BaseComponent
{
protected:
    Mediator* pMediator;
public:
    BaseComponent(Mediator* mediator = nullptr) :pMediator{ mediator } {}
    void setMediator(Mediator* mediator)
    {
        this->pMediator = mediator;
    }
};
//Concrete Components implement various functionality. They don't depend on other components. They also don't depend on any concrete mediator classes.
class Component1 : public BaseComponent
{
public:
    void doA()
    {
        std::cout << "Component 1 does A.\n";
        this->pMediator->notify(this, "A");
    }
    void doB()
    {
        std::cout << "Component 1 does B.\n";
        this->pMediator->notify(this, "B");
    }
};
class Component2 : public BaseComponent
{
public:
    void doC()
    {
        std::cout << "Component 2 does C.\n";
        this->pMediator->notify(this, "C");
    }
    void doD()
    {
        std::cout << "Component 2 does D.\n";
        this->pMediator->notify(this, "D");
    }
};

// Concrete Mediators implement cooperative behavior by coordinating several components.

class ConcreteMediator : public Mediator
{
private:
    Component1* m_pComponent1;
    Component2* m_pComponent2;
public:
    ConcreteMediator(Component1* pComponent1, Component2* pComponent2)
        : m_pComponent1{ pComponent1 }, m_pComponent2{ pComponent2 }
    {
        this->m_pComponent1->setMediator(this);
        this->m_pComponent2->setMediator(this);
    }
    void notify(BaseComponent* sender, std::string event) const override
    {
        if (event == "A")
        {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            this->m_pComponent2->doC();
        }
        if (event == "D")
        {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->m_pComponent1->doB();
            this->m_pComponent2->doC();
        }
    }
};

int main()
{
    Component1* component1 = new Component1;
    Component2* component2 = new Component2;

    ConcreteMediator* mediator = new ConcreteMediator(component1, component2);
    std::cout << "Client triggers operation A.\n";
    component1->doA();
    std::cout << "\n";
    std::cout << "Client triggers operation D.\n";
    component2->doD();

    delete component1;
    delete component2;
    delete mediator;

    return 0;
}

