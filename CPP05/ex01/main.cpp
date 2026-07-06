#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    //--------------NORMAL----------------
    std::cout << "--------------NORMAL----------------" << "\n";
    Bureaucrat bur0("Bob0", 50);
    Form con0("Contract0", 60, 70);

    try
    {
        bur0.signForm(con0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    std::cout << bur0 << "\n";
    std::cout << con0 << "\n";

    //--------------LOW----------------
    std::cout << "--------------LOW----------------" << "\n";
    Bureaucrat bur1("Bob1", 50);
    Form con1("Contract1", 10, 20);

    try
    {
        bur1.signForm(con1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << bur1 << "\n";
    std::cout << con1 << "\n";

    //--------------BUREAU HIGH----------------
    std::cout << "-------------- BUREAU HIGH----------------" << "\n";

    try
    {
        Bureaucrat bur2("Bob2", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //--------------BUREAU LOW----------------
    std::cout << "-------------- BUREAU LOW ----------------" << "\n";

    try
    {
        Bureaucrat bur2("Bob2", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //--------------FORM HIGH----------------
    std::cout << "--------------FORM HIGH----------------" << "\n";

    try
    {
        Bureaucrat bur2("Bob2", 100);
        Form con2("Contract2", 0, 50);
        bur2.signForm(con2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //--------------FORM LOW----------------
    std::cout << "--------------FORM LOW----------------" << "\n";

    try
    {
        Bureaucrat bur2("Bob2", 100);
        Form con2("Contract2", 151, 50);
        bur2.signForm(con2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
