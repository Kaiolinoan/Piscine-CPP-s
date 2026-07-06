#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 137, 145), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 137, 145), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    checkExecution(executor);
    
    std::ofstream file((_target + "_shruberry").c_str());

    file <<
    "   /\\\n"
    "  /**\\\n"
    " /****\\\n"
    "/******\\\n"
    "  ||||\n";
}
 