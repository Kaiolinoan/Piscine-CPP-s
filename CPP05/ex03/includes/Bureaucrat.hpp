#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "GradeTooLowException.hpp"
#include "GradeTooHighException.hpp"
#include "FormNotSignedException.hpp"
#include "AForm.hpp"
class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;

    public:
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat& operator=(const Bureaucrat& other);
    Bureaucrat& operator++();
    Bureaucrat& operator--();
    std::string get_name()  const;
    int         get_grade()  const;
    void        signForm(AForm &form);
    void        executeForm(AForm const & form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object);

#endif