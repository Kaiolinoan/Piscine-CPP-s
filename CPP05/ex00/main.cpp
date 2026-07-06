#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat normal("normal", 50);
    Bureaucrat high("high", 1);
    Bureaucrat low("low", 150);

    
    //--------------NORMAL----------------
    std::cout << "--------------NORMAL----------------" << "\n";
    std::cout << normal;
    
    //Decrement Test
    --normal;
    std::cout << normal;

    //Increment Test
    ++normal;
    std::cout << normal;

    //--------------HIGH------------------
    std::cout << "\n" << "--------------HIGH----------------" << "\n";
    std::cout << high;

    //Increment Test
    try
    {
        ++high;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    std::cout << high;
    
    //--------------LOW-------------------
    std::cout << "\n" << "--------------LOW----------------" << "\n";
    std::cout << low;
    
    //Decrement Test
    try
    {
        --low;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    std::cout << low;
    
    //--------------INVALID CONSTRUCTION-------------------
    std::cout << "\n" << "--------------INVALID CONSTRUCTION----------------" << "\n";
    try
    {
        Bureaucrat a("A", 0);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        Bureaucrat b("B", 151);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}