// StatebehavioralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>

class Context;

// Base State 
class State {
 protected:
    Context* m_pcontext; // reference to the Context object associated with the State to transition the Context to another State

public:
    virtual ~State() {
    }

    void set_context(Context* context) {
        this->m_pcontext = context;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
};

// Context class

class Context {
private:
    State* m_pstate; // State A reference to the current state of the Context

public:
    Context(State* state) : m_pstate(nullptr) {
        this->TransitionTo(state);
    }
    ~Context() {
        delete m_pstate;
    }
// The Context allows changing the State object at runtime.
    void TransitionTo(State* state) {
        std::cout << "Context: Transition to " << typeid(*state).name() << ".\n";
        if (this->m_pstate != nullptr)
            delete this->m_pstate;
        this->m_pstate = state;
        this->m_pstate->set_context(this);
    }
    // The Context delegates part of its behavior to the current State object.
    void Request1() {
        this->m_pstate->Handle1();
    }
    void Request2() {
        this->m_pstate->Handle2();
    }
};

// Concrete States implement various behaviors, associated with a state of the Context.

class ConcreteStateA : public State {
public:
    void Handle1() override;

    void Handle2() override {
        std::cout << "ConcreteStateA handles request2.\n";
    }
};

class ConcreteStateB : public State {
public:
    void Handle1() override {
        std::cout << "ConcreteStateB handles request1.\n";
    }
    void Handle2() override {
        std::cout << "ConcreteStateB handles request2.\n";
        std::cout << "ConcreteStateB wants to change the state of the context.\n";
        this->m_pcontext->TransitionTo(new ConcreteStateA);
    }
};

void ConcreteStateA::Handle1() {
    {
        std::cout << "ConcreteStateA handles request1.\n";
        std::cout << "ConcreteStateA wants to change the state of the context.\n";
        this->m_pcontext->TransitionTo(new ConcreteStateB);
    }
}

// Client code.
void ClientCode() {
    Context* context = new Context(new ConcreteStateA);
    context->Request1();
    context->Request2();
    delete context;
}

int main() {
    ClientCode();
    return 0;
}
