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
        virtual ~AForm();
        AForm(const std::string &name, int ExecGrade, int SignGrade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        void beSigned(const Bureaucrat& bur);
        void checkExecution(const Bureaucrat& executor) const;
        std::string  getName() const;
        int          getSignGrade() const;
        int          getExecGrade() const;
        bool         getSigned() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& object);

#endif