#ifndef AFORM_H
#define AFORM_H
#include <iostream>
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _signed;
    public:
        //CONSTRUCTORS AND DESTRUCTOR
        virtual ~AForm();
        AForm(const std::string &name, int ExecGrade, int SignGrade);
        AForm(const AForm& other);

        //OPERATORS
        AForm& operator=(const AForm& other);

        //METHODS
        void beSigned(const Bureaucrat& bur);
        void checkExecution(const Bureaucrat& executor) const;
        virtual void execute(Bureaucrat const & executor) const = 0;

        //GETTERS
        std::string  getName() const;
        int          getSignGrade() const;
        int          getExecGrade() const;
        bool         getSigned() const;

        //EXCEPTIONS
        class FormNotSignedException : std::exception
        {
            virtual const char * what() const throw();
        };
        class GradeTooHighException : std::exception
        {
            virtual const char * what() const throw();
        };
        class GradeTooLowException : std::exception
        {
            virtual const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& object);

#endif