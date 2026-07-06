#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm() {};

AForm::AForm(const std::string &name, int ExecGrade, int SignGrade) 
: _name(name), _signGrade(SignGrade), _execGrade(ExecGrade), _signed(false)
{
    if (ExecGrade > 150)
		throw GradeTooLowException();
    if (SignGrade > 150)
		throw GradeTooLowException();
	if (ExecGrade < 1) 
		throw GradeTooHighException();
	if (SignGrade < 1) 
		throw GradeTooHighException();
};

std::string AForm::getName() const { return (this->_name); };

bool AForm::getSigned() const { return (this->_signed); };

int AForm::getExecGrade() const { return (this->_execGrade);  };

int AForm::getSignGrade() const { return (this->_signGrade);  };

void AForm::beSigned(const Bureaucrat& bur)
{
	if (this->_signed)
		return;
	if (bur.get_grade() <= this->getSignGrade())
		this->_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
	if (!this->_signed)
		throw FormNotSignedException();
	if (executor.get_grade() > this->getExecGrade())
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& object)
{
	std::string sign_out;

	if (!object.getSigned())
		sign_out = "false";
	else 
		sign_out = "true";
	out << "form's name: " << object.getName() << ", form's sign: " << sign_out
    << ", form's execute grade: " << object.getExecGrade()
    << ", form's sign grade: " << object.getSignGrade();
	return (out);
}   