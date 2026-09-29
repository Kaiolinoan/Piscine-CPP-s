#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;

    public:
    //CONSTRUCTOR AND DESTRUCTORS
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat(const std::string& name, int grade);

    //OPERATORS
    Bureaucrat& operator=(const Bureaucrat& other);
    Bureaucrat& operator++();
    Bureaucrat& operator--();

    //GETTERS
    std::string getName()  const;
    int         getGrade()  const;

    //METHODS
    void        signForm(AForm &form);
    void        executeForm(AForm const & form) const;

    //EXCEPTIONS
    class GradeTooHighException : std::exception
    {
        virtual const char * what() const throw();
    };
    class GradeTooLowException : std::exception
    {
        virtual const char * what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object);

#endif