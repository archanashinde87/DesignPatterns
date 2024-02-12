#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Component
class Graphic
{
public:
    virtual ~Graphic(){}
    virtual void print() const = 0;
};

// Composite
class GraphicComposite : public Graphic
{
private:
    std::vector<const Graphic*> children;
    const std::string& m_name{};
public:
    explicit GraphicComposite(const std::string& name) : m_name{name}{}
    void print() const override
    {
        std::cout << m_name << " ";
        for (auto const child : children)
            child->print();
    }
    
    void addComp(const Graphic* component)
    {
        children.push_back(component);
    }
    
    void removeComp(const Graphic* component)
    {
        erase(children, component);
    }
};

// Leaf
class Ellipse : public Graphic
{
private: 
    const std::string& m_name{};
public:
    explicit Ellipse(const std::string& name):m_name{name}{}
    void print() const override
    {
        std::cout << m_name << " ";
    }
};
int main()
{
    const std::string el1 = "ellipse1";
    const std::string el2 = "ellipse2";
    const std::string el3 = "ellipse3";
    const std::string el4 = "ellipse4";
    
    Ellipse ellipse1{el1};
    Ellipse ellipse2{el2};
    Ellipse ellipse3{el3};
    Ellipse ellipse4{el4};
    
    const std::string graph1 = "graphic1";
    const std::string graph2 = "graphic2";
    const std::string graph3 = "graphic3";
    
    GraphicComposite graphic1{graph1};
    GraphicComposite graphic2{graph2};
    GraphicComposite graphic3{graph3};
    
    graphic1.addComp(&ellipse1);
    graphic1.addComp(&ellipse2);
    graphic1.addComp(&ellipse3);
    
    graphic2.addComp(&ellipse4);
    
    graphic3.addComp(&graphic1);
    graphic3.addComp(&graphic2);
    
    graphic1.print();
    std::cout << '\n';
    graphic2.print();
    std::cout << '\n';
    
    graphic3.print();
    std::cout << '\n';
    graphic3.removeComp(&graphic1);
    graphic3.print();
    std::cout << "\n\n";

    return 0;
}