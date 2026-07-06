#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP
#include <iostream>
#include <exception>

class GradeTooLowException: public std::exception
{
    private:
    std::string _message;
    public:
    GradeTooLowException();
    virtual ~GradeTooLowException() throw() {}
    const char* what() const throw();
};
#endif