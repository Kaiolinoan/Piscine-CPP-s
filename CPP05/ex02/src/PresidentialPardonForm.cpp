#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 5, 25), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
};

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    checkExecution(executor);

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

