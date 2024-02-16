// MementoBehavioralDesignPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

// Originator: The object whose state needs to be saved and restored.
class Originator
{
private:
    std::string m_state{};
public:
    void setState(const std::string& newState) { m_state = newState; }
    std::string getState() const { return m_state; }

    // Memento: Inner class representing the state of the Originator.
    class Memento
    {
    private: 
        std::string m_state{};
    public:
        Memento(const std::string& originatorState) :m_state{ originatorState } {}
        std::string getSavedState() const { return m_state; }
    };

    // Create a Memento object to save the current state.
    Memento createMemento() const { return Memento(m_state);}
    // Restore the state from a Memento object.
    void restoreState(const Memento& memento)
    {
        m_state = memento.getSavedState();
    }
};

// Caretaker: Manages the Memento objects.
class Caretaker
{
private:
    std::vector<Originator::Memento>m_mementos;
public:
    void addMemento(const Originator::Memento& memento)
    {
        m_mementos.push_back(memento);
    }
    Originator::Memento getMemento(int index) const
    {
        if (index >= 0 && index < m_mementos.size())
            return m_mementos[index];
        throw std::out_of_range("Invalid Memento index");
    }
};

int main()
{
    Originator originator;
    Caretaker caretaker;

    originator.setState("State 1");
    caretaker.addMemento(originator.createMemento());
    originator.setState("State 2");
    caretaker.addMemento(originator.createMemento());

    // restore to the previous state
    originator.restoreState(caretaker.getMemento(0));
    std::cout << "Current state: " << originator.getState() << std::endl;

    // restore to an even earlier state
    originator.restoreState(caretaker.getMemento(1));
    std::cout << "Current state: " << originator.getState() << std::endl;

    return 0;
}

