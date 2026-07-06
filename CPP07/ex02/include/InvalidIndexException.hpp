#ifndef INVALIDINDEXEXCEPTION_HPP
#define INVALIDINDEXEXCEPTION_HPP
#include <iostream>
#include <exception>
class InvalidIndex: public std::exception
{
    private:
    std::string _message;
    public:
    InvalidIndex();
    virtual ~InvalidIndex() throw() {}
    const char* what() const throw();
};
#endif