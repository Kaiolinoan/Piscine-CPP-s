#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 137, 145), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
       AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    checkExecution(executor);
    
    std::ofstream file((_target + "_shrubbery").c_str());

    file <<
    "   /\\\n"
    "  /**\\\n"
    " /****\\\n"
    "/******\\\n"
    "  ||||\n";
}
 