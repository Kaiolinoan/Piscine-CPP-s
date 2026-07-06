#include "Base.hpp"

Base::~Base() {}

Base* generate()
{

    int num = rand() % 3;
    if (num == 0)
        return (new A());
    else if (num == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base* p) 
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p) 
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch(const std::exception& e){}
    
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    }
    catch(const std::exception& e){}
    
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch(const std::exception& e){}   
}