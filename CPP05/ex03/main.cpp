#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main ()
{
    Intern intern1;

    AForm *form1;
    AForm *form2;
    AForm *form3;

    form1 = intern1.makeForm("robotomy request", "Jarvis");
    form2 = intern1.makeForm("presidential pardon", "Jason");
    form3 = intern1.makeForm("shrubbery creation", "Home");

    //--------------RobotomyRequestForm----------------
    if (form1)
    {
        std::cout << "\n--------------RobotomyRequestForm----------------" << "\n\n";
        Bureaucrat boss("Boss", 1);

        boss.signForm(*form1);
        boss.executeForm(*form1);

        delete form1;
    }

    //--------------PresidentialPardonForm----------------
    if (form2)
    {
        std::cout << "\n--------------PresidentialPardonForm----------------" << "\n\n";
        Bureaucrat boss("Boss", 1);

        boss.signForm(*form2);
        boss.executeForm(*form2);

        delete form2;
    }

    //--------------ShrubberyCreationForm----------------
    if (form3)
    {
        std::cout << "\n--------------ShrubberyCreationForm----------------" << "\n\n";
        Bureaucrat boss("Boss", 1);

        boss.signForm(*form3);
        boss.executeForm(*form3);

        delete form3;
    }
}

