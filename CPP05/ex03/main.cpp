#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main ()
{

//--------------RobotomyRequestForm----------------
    try
    {
        //--------------RobotomyRequestForm NORMAL----------------
        std::cout << "\n--------------RobotomyRequestForm NORMAL----------------" << "\n\n";
        Intern intern1;
        AForm *form1;
        form1 = intern1.makeForm("robotomy request", "Jarvis");
        Bureaucrat bur1("bur1", 1);
        bur1.signForm(*form1);
        bur1.executeForm(*form1);
        delete form1;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------RobotomyRequestForm LOW----------------
        std::cout << "\n--------------RobotomyRequestForm LOW----------------" << "\n\n";
        Intern intern1;
        AForm *form1;
        form1 = intern1.makeForm("robotomy request", "Jarvis");
        Bureaucrat bur1("bur1", 50);
        bur1.signForm(*form1);
        bur1.executeForm(*form1);
        delete form1;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------RobotomyRequestForm NOT SIGNED----------------
        std::cout << "\n--------------RobotomyRequestForm NOT SIGNED----------------" << "\n\n";
        Intern intern1;
        AForm *form1;
        form1 = intern1.makeForm("robotomy request", "Jarvis");
        Bureaucrat bur1("bur1", 1);
        bur1.executeForm(*form1);
        delete form1;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
//--------------PresidentialPardonForm----------------
    try
    {
        //--------------PresidentialPardonForm NORMAL----------------
        std::cout << "--------------PresidentialPardonForm NORMAL----------------" << "\n\n";
        Intern intern2;
        AForm *form2;
        form2 = intern2.makeForm("presidential pardon", "Jason");
        Bureaucrat bur1("bur1", 1);
        bur1.signForm(*form2);
        bur1.executeForm(*form2);
        delete form2;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        //--------------PresidentialPardonForm LOW----------------
        std::cout << "\n--------------PresidentialPardonForm LOW----------------" << "\n\n";
        Bureaucrat bur1("bur1", 10);
        Intern intern2;
        AForm *form2;
        form2 = intern2.makeForm("presidential pardon", "Jason");
        bur1.signForm(*form2);
        bur1.executeForm(*form2);
        delete form2;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        //--------------PresidentialPardonForm NOT SIGNED----------------
        std::cout << "\n--------------PresidentialPardonForm NOT SIGNED----------------" << "\n\n";
        Intern intern2;
        AForm *form2;
        form2 = intern2.makeForm("presidential pardon", "Jason");
        Bureaucrat bur1("bur1", 149);
        bur1.executeForm(*form2);
        delete form2;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
//--------------ShrubberyCreationForm----------------
    try
    {
        //--------------ShrubberyCreationForm NORMAL----------------
        std::cout << "\n--------------ShrubberyCreationForm NORMAL----------------" << "\n\n";
        Intern intern3;
        AForm *form3;
        form3 = intern3.makeForm("shrubbery creation", "Home");
        Bureaucrat bur1("bur1", 1);
        bur1.signForm(*form3);
        bur1.executeForm(*form3);
        delete form3;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        //--------------ShrubberyCreationForm LOW----------------
        std::cout << "\n--------------ShrubberyCreationForm LOW----------------" << "\n\n";
        Bureaucrat bur1("bur1", 140);
        Intern intern3;
        AForm *form3;
        form3 = intern3.makeForm("shrubbery creation", "Home");
        bur1.signForm(*form3);
        bur1.executeForm(*form3);
        delete form3;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        //--------------ShrubberyCreationForm NOT SIGNED----------------
        std::cout << "\n--------------ShrubberyCreationForm NOT SIGNED----------------" << "\n\n";
        Bureaucrat bur1("bur1", 149);
        Intern intern3;
        AForm *form3;
        form3 = intern3.makeForm("shrubbery creation", "Home");
        bur1.executeForm(*form3);
        delete form3;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}