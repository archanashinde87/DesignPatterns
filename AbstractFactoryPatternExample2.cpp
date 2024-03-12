/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

// Abstract Product1 - Chair
class Chair
{
public:
   virtual void hasLegs() = 0;
   virtual void sitOn() = 0;
};
// Abstract Product2 - Sofa
class Sofa
{
public:
   virtual void hasThreeSeats() = 0;
};

// Abstract Product3 - Coffee Table
class CoffeeTable
{
public:
   virtual void holdsCoffeeTray() = 0;
};

// Concrete Product1 - ModernChair
class ModernChair : public Chair
{
public:
   void hasLegs() override
   {
       std::cout << "Modern Chair does not have proper legs.\n";
   }
   void sitOn() override
   {
       std::cout << "Modern chair is used by young gen to sit on.\n";
   }
};
// Concrete Product2 - ModernSofa
class ModernSofa : public Sofa
{
public:
   void hasThreeSeats() override
   {
       std::cout << "Modern Sofa has proper 3&1/2 seats.\n";
   }
};

// Concrete Product3 - ModernCoffeeTable
class ModernCoffeeTable : public CoffeeTable
{
public:
   void holdsCoffeeTray() override
   {
       std::cout << "Modern Coffee Table looks very decent and feels like will fall.\n";
   }
};

// Concrete Product1 - VictorianChair
class VictorianChair : public Chair
{
public:
   void hasLegs() override
   {
       std::cout << "Victorian Chair does have proper legs.\n";
   }
   void sitOn() override
   {
       std::cout << "Victorian chair is used by old gen to sit on.\n";
   }
};
// Concrete Product2 - VictorianSofa
class VictorianSofa : public Sofa
{
public:
   void hasThreeSeats() override
   {
       std::cout << "Victorian Sofa has only 3 seats.\n";
   }
};

// Concrete Product3 - ModernCoffeeTable
class VictorianCoffeeTable : public CoffeeTable
{
public:
   void holdsCoffeeTray() override
   {
       std::cout << "Victorian Coffee Table looks antique piece and comfortable to use.\n";
   }
};

// Abstract Factory
class FurnitureFactory
{
public:
    virtual Chair* createChair() const = 0;
    virtual Sofa* createSofa() const = 0;
    virtual CoffeeTable* createCoffeeTable() const = 0;
};

// Concrete ModernFurnitureFactory
class ModernFurnitureFactory : public FurnitureFactory
{
public:
    Chair* createChair() const override
    {
        return new ModernChair();
    }
    Sofa* createSofa() const override
    {
        return new ModernSofa();
    }
    CoffeeTable* createCoffeeTable() const override
    {
        return new ModernCoffeeTable();
    }
};

// Concrete VictorianFurnitureFactory
class VictorianFurnitureFactory : public FurnitureFactory
{
public:
    Chair* createChair() const override
    {
        return new VictorianChair();
    }
    Sofa* createSofa() const override
    {
        return new VictorianSofa();
    }
    CoffeeTable* createCoffeeTable() const override
    {
        return new VictorianCoffeeTable();
    }
};

void clientCode(const FurnitureFactory& factory)
{
    Chair* chair = factory.createChair();
    chair->hasLegs();
    chair->sitOn();
    
    Sofa* sofa = factory.createSofa();
    sofa->hasThreeSeats();

    CoffeeTable* coffeeTable = factory.createCoffeeTable();
    coffeeTable->holdsCoffeeTray();
 
    delete chair;
    delete sofa;
    delete coffeeTable;
}

int main()
{
    std::cout << "These products are from Modern Furniture Factory: \n";
    ModernFurnitureFactory* mfFactory = new ModernFurnitureFactory();
    clientCode(*mfFactory);
    std::cout << "These products are from Victorian Furniture Factory: \n";
    VictorianFurnitureFactory* vfFactory = new VictorianFurnitureFactory();
    clientCode(*vfFactory);
  
    return 0;
}
