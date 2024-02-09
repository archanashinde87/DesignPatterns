/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
#include <thread>

class Singleton
{
private:
    std::string m_value{};
    static Singleton* pSingletonInstance;
    Singleton(const std::string& value)
    :m_value{value}
    {}
    ~Singleton() = default;
    
public:
    static Singleton* getInstance(const std::string& value);
    std::string getValue() const {return m_value;}
    void someOperation();
    Singleton(const Singleton&)=delete;
    Singleton& operator=(const Singleton&)=delete;
    
};

Singleton* Singleton::pSingletonInstance=nullptr;
Singleton* Singleton::getInstance(const std::string& value)
{
    if(pSingletonInstance==nullptr)
    {
        pSingletonInstance = new Singleton(value); // lazy initialization
    }
    return pSingletonInstance;
}

void Singleton::someOperation()
{
    std::cout << "This is just for some business logic.\n";
}

void ThreadBar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* pSingletonInst = Singleton::getInstance("Bar");
    std::cout << pSingletonInst->getValue() << "\n";
}

void ThreadFoo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* pSingletonInst = Singleton::getInstance("Foo");
    std::cout << pSingletonInst->getValue() << "\n";
}

int main()
{
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
                "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
                "RESULT:\n";   

    std::thread thread1(ThreadFoo);
    std::thread thread2(ThreadBar);
    
    thread1.join();
    thread2.join();
    
    return 0;
}
