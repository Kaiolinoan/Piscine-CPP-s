#ifndef FORMNOTSIGNEDEXCEPTION_HPP
#define FORMNOTSIGNEDEXCEPTION_HPP
#include <iostream>
#include <exception>
class FormNotSignedException: public std::exception
{
    private:
        std::string _message;
    public:
        FormNotSignedException();
        virtual ~FormNotSignedException() throw() {}
        const char* what() const throw();
};
#endif