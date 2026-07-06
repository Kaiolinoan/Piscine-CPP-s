#ifndef GRADETOOHIGHEXCEPTION_HPP
#define GRADETOOHIGHEXCEPTION_HPP
#include <iostream>
#include <exception>
class GradeTooHighException: public std::exception
{
    private:
    std::string _message;
    public:
    GradeTooHighException();
    virtual ~GradeTooHighException() throw() {}
    const char* what() const throw();
};
#endif