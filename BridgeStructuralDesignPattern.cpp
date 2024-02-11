#include <iostream>

using namespace std;

// Abstrction
class Shape
{
public:
    virtual void draw() const = 0;
};

//Implementations Renderer(VectorRenderer & RasterRenderer)
class Renderer
{
public:
    virtual void render() const = 0;
};
class VectorRenderer : public Renderer
{
public:
    void render() const override
    {
        std::cout << "Rendering as a vector.\n";
    }
};
class RasterRenderer : public Renderer
{
public:
    void render() const override
    {
        std::cout << "Rendering as a raster.\n";
    }
};

// Concrete Abstractions Circle and Square
class Circle : public Shape
{
private: 
    Renderer& m_renderer;
public:
    Circle(Renderer& renderer):m_renderer{renderer}
    {}
    void draw() const override
    {
        std::cout << "Drawing a Circle ";
        m_renderer.render();
    }
};

class Square : public Shape
{
private: 
    Renderer& m_renderer;
public:
    Square(Renderer& renderer):m_renderer{renderer}
    {}
    void draw() const override
    {
        std::cout << "Drawing a Square ";
        m_renderer.render();
    }
};

int main()
{
    VectorRenderer vectorRenderer;
    RasterRenderer rasterRenderer;
    
    Circle circle(vectorRenderer);
    Square square(rasterRenderer);
    circle.draw();
    square.draw();
    
    return 0;
}