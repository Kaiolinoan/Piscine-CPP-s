#ifndef FORM_H
#define FORM_H
#include <iostream>
class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _signed;
    public:
        ~Form();
        Form(const std::string &name, int ExecGrade, int SignGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        void beSigned(const Bureaucrat& bur);
        std::string getName() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        bool        getSigned() const;
};

std::ostream& operator<<(std::ostream& out, const Form& object);

#endif