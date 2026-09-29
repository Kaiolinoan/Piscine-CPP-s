#ifndef FORM_H
#define FORM_H
#include <iostream>
#include <exception>
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _signed;
    public:

        //CONSTRUCTORS AND DESTUCTOR
        ~Form();
        Form(const std::string &name, int ExecGrade, int SignGrade);
        Form(const Form& other);

        //OPERATORS
        Form& operator=(const Form& other);

        //METHODS
        void beSigned(const Bureaucrat& bur);

        //GETTERS
        std::string getName() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        bool        getSigned() const;

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

std::ostream& operator<<(std::ostream& out, const Form& object);

#endif