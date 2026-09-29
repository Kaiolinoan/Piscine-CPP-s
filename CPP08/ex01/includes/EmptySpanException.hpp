#ifndef EMPTYSPANEXCEPTION_HPP
#define EMPTYSPANEXCEPTION_HPP
#include <iostream>
#include <exception>
class EmptySpan: public std::exception
{
    private:
    std::string _message;
    public:
    EmptySpan();
    virtual ~EmptySpan() throw() {}
    const char* what() const throw();
};
#endif