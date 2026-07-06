#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
class Intern
{
    private:
        AForm* createRobotomy(const std::string& target);
        AForm* createPresidential(const std::string& target);
        AForm* createShrubbery(const std::string& target);
    public:
        ~Intern();
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm *makeForm(const std::string& FormName, const std::string& FormTarget);
};

#endif