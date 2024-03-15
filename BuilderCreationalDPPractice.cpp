/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

// Product
class Pizza
{
private:
    std::string m_dough{};
    std::string m_sauce{};
    std::string m_topping{};
public:
    void setDough(std::string dough)
    {
        m_dough = dough;
    }
    void setSauce(std::string sauce)
    {
        m_sauce = sauce;
    }
    void setTopping(std::string topping)
    {
        m_topping = topping;
    }
    void displayPizza()
    {
        std::cout << "Pizza with Dough: " << m_dough
                  << ", Sauce: " << m_sauce
                  << ", Topping: " << m_topping << std::endl;
    }

};
// Builder
class PizzaBuilder
{
public:
    virtual void buildDough()=0;
    virtual void buildSauce()=0;
    virtual void buildTopping()=0;
    virtual Pizza getPizza() const = 0;
     
};

// Concrete Builder
class HawaiianPizzaBuilder : public PizzaBuilder
{
private:
    Pizza m_pizza;
    
public:
    void buildDough() override
    {
        m_pizza.setDough("Hawaiian Dough");
    }
    void buildSauce() override
    {
        m_pizza.setSauce("Hawaiian Sauce");
    }
    void buildTopping() override
    {
       m_pizza.setTopping("Hawaiian Topping");
    }
    Pizza getPizza() const override
    {
        return m_pizza;
    }
    
};

// Concrete Builder
class SpicyPizzaBuilder : public PizzaBuilder
{
private:
    Pizza m_pizza;
    
public:
    void buildDough() override
    {
        m_pizza.setDough("Spicy Dough");
    }
    void buildSauce() override
    {
        m_pizza.setSauce("Spicy Sauce");
    }
    void buildTopping() override
    {
       m_pizza.setTopping("Spicy Topping");
    }
    Pizza getPizza() const override
    {
        return m_pizza;
    }
    
};

// Director
class Cook
{
public:
    void makePizza(PizzaBuilder& pizzaBuilder)
    {
      pizzaBuilder.buildDough();
      pizzaBuilder.buildSauce();
      pizzaBuilder.buildTopping();
    }
};

int main()
{

    Cook cook;
 
    HawaiianPizzaBuilder hawaiianBuilder;
    cook.makePizza(hawaiianBuilder);
    Pizza hawaiianPizza = hawaiianBuilder.getPizza();
    hawaiianPizza.displayPizza();
 
    SpicyPizzaBuilder spicyBuilder;
    cook.makePizza(spicyBuilder);
    Pizza spicyPizza = spicyBuilder.getPizza();
    spicyPizza.displayPizza();

    return 0;
}
