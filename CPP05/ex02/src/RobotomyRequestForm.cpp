#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 45, 72), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 45, 72), _target(other._target) {}; 

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) 
{
    if (this != &other)
    {
        this->_target = other._target;
    }
    return (*this);
};

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    checkExecution(executor);
    std::srand(std::time(NULL));
    std::cout << "Drilling noises\n";

    int random = rand() % 2;
    if (random % 2 == 0)
        std::cout << _target << " has been robotomized successfully\n";
    else
        std::cout << "Robotomy failed\n";
}