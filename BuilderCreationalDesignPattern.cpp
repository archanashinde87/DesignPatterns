/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

// Product
class Computer
{
public:
    void set_cpu(const std::string& cpu){m_cpu=cpu;}
    void set_memory(const std::string& memory){m_memory=memory;}
    void set_storage(const std::string& storage){m_storage=storage;}
    void display()
    {
        std::cout << "CPU: " << m_cpu << std::endl;
        std::cout << "Memory: " << m_memory << std::endl;
        std::cout << "Storage: " << m_storage << std::endl;
    }

private:
    std::string m_cpu{};
    std::string m_memory{};
    std::string m_storage{};
};

// Builder Interface
class ComputerBuilder
{
public:
    virtual void buildCPU(const std::string& cpu) = 0;
    virtual void buildMemory(const std::string& memory)  = 0;
    virtual void buildStorage(const std::string& storage)  = 0;
    virtual Computer getResult() = 0;
};

// Concrete Builder
class DesktopComputerBuilder : public ComputerBuilder
{
public:
    DesktopComputerBuilder() 
    {
        m_Computer = Computer();
    }
    void buildCPU(const std::string& cpu) override
    {
        m_Computer.set_cpu(cpu);
    }
    void buildMemory(const std::string& memory) override
    {
        m_Computer.set_memory(memory);
    }
    void buildStorage(const std::string& storage) override
    {
        m_Computer.set_storage(storage);
    }
    Computer getResult() override
    {
        return m_Computer;
    }

private:
    Computer m_Computer{};
};

// Director
class ComputerAssembler 
{
public:
    Computer assembleComputer(ComputerBuilder& builder)
    {
       builder.buildCPU("Intel i7");
       builder.buildMemory("16 GB");
       builder.buildStorage("512GB SSD");
       return builder.getResult();
    }
};

int main()
{
    DesktopComputerBuilder desktopBuilder;
    ComputerAssembler computerAssembler;
    Computer desktop = computerAssembler.assembleComputer(desktopBuilder);
    
    std::cout << "Desktop Computer Configuration:" << std::endl;
    desktop.display();
    
    return 0;
}
