#ifndef FULLSPANEXCEPTION_HPP
#define FULLSPANEXCEPTION_HPP
#include <iostream>
#include <exception>
class FullSpan: public std::exception
{
    private:
    std::string _message;
    public:
    FullSpan();
    virtual ~FullSpan() throw() {}
    const char* what() const throw();
};
#endif