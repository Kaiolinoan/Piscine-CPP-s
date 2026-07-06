#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main ()
{
    try
    {
        //--------------PresidentialPardonForm NORMAL----------------
        std::cout << "--------------PresidentialPardonForm NORMAL----------------" << "\n\n";
        AForm *pres = new PresidentialPardonForm("Ze");
        Bureaucrat bur1("bur1", 1);
        bur1.signForm(*pres);
        bur1.executeForm(*pres);
        delete pres;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------PresidentialPardonForm LOW----------------
        std::cout << "\n--------------PresidentialPardonForm LOW----------------" << "\n\n";
        AForm *pres = new PresidentialPardonForm("Ze");
        Bureaucrat bur1("bur1", 149);
        bur1.signForm(*pres);
        bur1.executeForm(*pres);
        delete pres;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------PresidentialPardonForm NOT SIGNED----------------
        std::cout << "\n--------------PresidentialPardonForm NOT SIGNED----------------" << "\n\n";
        AForm *pres = new PresidentialPardonForm("Ze");
        Bureaucrat bur1("bur1", 149);
        bur1.executeForm(*pres);
        delete pres;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------RobotomyRequestForm NORMAL----------------
        std::cout << "\n--------------RobotomyRequestForm NORMAL----------------" << "\n\n";
        AForm *robot = new RobotomyRequestForm("Robo");
        Bureaucrat bur1("bur1", 1);
        bur1.signForm(*robot);
        bur1.executeForm(*robot);
        delete robot;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------RobotomyRequestForm LOW----------------
        std::cout << "\n--------------RobotomyRequestForm LOW----------------" << "\n\n";
        AForm *robot = new RobotomyRequestForm("Robo");
        Bureaucrat bur1("bur1", 149);
        bur1.signForm(*robot);
        bur1.executeForm(*robot);
        delete robot;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------RobotomyRequestForm NOT SIGNED----------------
        std::cout << "\n--------------RobotomyRequestForm NOT SIGNED----------------" << "\n\n";
        AForm *robot = new RobotomyRequestForm("Robo");
        Bureaucrat bur1("bur1", 1);
        bur1.executeForm(*robot);
        delete robot;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------ShrubberyCreationForm NORMAL----------------
        std::cout << "\n--------------ShrubberyCreationForm NORMAL----------------" << "\n\n";
        AForm *shru = new ShrubberyCreationForm("Berry");
        Bureaucrat bur1("bur1", 1);
        bur1.signForm(*shru);
        bur1.executeForm(*shru);
        delete shru;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------ShrubberyCreationForm LOW----------------
        std::cout << "\n--------------ShrubberyCreationForm LOW----------------" << "\n\n";
        AForm *shru = new ShrubberyCreationForm("Berry");
        Bureaucrat bur1("bur1", 149);
        bur1.signForm(*shru);
        bur1.executeForm(*shru);
        delete shru;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        //--------------ShrubberyCreationForm NOT SIGNED----------------
        std::cout << "\n--------------ShrubberyCreationForm NOT SIGNED----------------" << "\n\n";
        AForm *shru = new ShrubberyCreationForm("Berry");
        Bureaucrat bur1("bur1", 149);
        bur1.executeForm(*shru);
        delete shru;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}
