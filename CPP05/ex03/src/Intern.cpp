#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::~Intern() {};

Intern::Intern() {};

AForm* Intern::createRobotomy(const std::string& target)
{
    std::cout << "Intern creates RobotomyRequestForm\n"; 
    return (new RobotomyRequestForm(target));
}
AForm* Intern::createPresidential(const std::string& target)
{
    std::cout << "Intern creates PresidentialPardonForm\n"; 
    return (new PresidentialPardonForm(target));
}
AForm* Intern::createShrubbery(const std::string& target)
{
    std::cout << "Intern creates ShrubberyCreationForm\n"; 
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(const std::string& FormName, const std::string& FormTarget)
{
    std::string names[3]  = {"robotomy request", "presidential pardon", "shrubbery creation"};
    typedef AForm * (Intern::*FormCreator)(const std::string&);
    FormCreator creators[3] = {&Intern::createRobotomy, &Intern::createPresidential, &Intern::createShrubbery};
    for (int i = 0; i < 3; i++)
    {
        if (FormName == names[i])
            return (this->*creators[i])(FormTarget);
    }
    std::cout << "Failed to create Form\n";
    return (NULL);
}