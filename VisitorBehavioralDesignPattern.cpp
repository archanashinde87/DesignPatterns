/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

// Forward Declarations
class Circle;
class Rectangle;

// Visitor Interface
class ShapeVisitor
{
public:
    virtual void visit(Circle& circle) = 0;
    virtual void visit(Rectangle& rectangle) = 0;
};

// Element Interface
class Shape
{
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
};

// Cooncrete Element : Circle
class Circle : public Shape
{
public:
    void accept(ShapeVisitor& visitor) override
    {
        visitor.visit(*this);
    }
    void draw()
    {
       std::cout << "Drawing Circle\n"; 
    }
};
// Cooncrete Element : Rectangle
class Rectangle : public Shape
{
public:
    void accept(ShapeVisitor& visitor) override
    {
        visitor.visit(*this);
    }
    void draw()
    {
       std::cout << "Drawing Rectangle\n"; 
    }
};

// Concrete Visitor : DrawingVisitor
class DrawingVisitor : public ShapeVisitor
{
public:
    void visit(Circle& circle) override
    {
        std::cout << "Drawing a Circle\n";
        circle.draw();
    }
    void visit(Rectangle& rectangle) override
    {
        std::cout << "Drawing a Rectangle\n";
        rectangle.draw();
    }
};
// Concrete Visitor : AreaVisitor
class AreaVisitor : public ShapeVisitor
{
public:
    void visit(Circle& circle) override
    {
        std::cout << "Calculating area of Circle\n";
        // Calculate and print area logic for Circle
    }
    void visit(Rectangle& rectangle) override
    {
        std::cout << "Calculating area of Rectangle\n";
        // Calculate and print area logic for Rectangle    
    }
};

// Object Structure
class ShapeContainer
{
 private:
    std::vector<Shape*> container;
public:
    void addShape(Shape* shape)
    {
        container.push_back(shape);
    }
    void performOperations(ShapeVisitor& visitor)
    {
        for(Shape* shape : container)
            shape->accept(visitor);
    }
};
int main()
{
    // Create instances of shapes
    Circle circle;
    Rectangle rectangle;
    
    // Create a container and add shapes to it
    ShapeContainer container;
    container.addShape(&circle);
    container.addShape(&rectangle);
    
     // Create visitors
    DrawingVisitor drawingVisitor;
    AreaVisitor areaVisitor;
    
    // perform drawing Operations
    container.performOperations(drawingVisitor);
    
    // perform  calculating area Operations
    container.performOperations(areaVisitor);

    return 0;
}
