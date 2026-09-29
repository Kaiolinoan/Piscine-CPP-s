#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;

    public:

    //CONSTRUCTORS AND DESTRUCTOR
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
    void        signForm(Form &form);

    //EXCEPTIONS
    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object);

#endif