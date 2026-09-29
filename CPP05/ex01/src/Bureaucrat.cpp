#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade; 
};

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return (*this);
};

std::string Bureaucrat::getName() const { return (this->_name); }

int         Bureaucrat::getGrade() const { return (this->_grade); }

Bureaucrat& Bureaucrat::operator++()
{
	if (this->_grade > 1)
		this->_grade--;
	else 
		throw GradeTooHighException();
	return (*this);
}

Bureaucrat& Bureaucrat::operator--()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw GradeTooLowException();
	return (*this);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " succesfully signed " << form.getName() << "\n";
	}
	catch (std::exception &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
	}
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& object)
{
	out << object.getName() << ", bureaucrat grade " << object.getGrade();
	return (out);
}

const char * Bureaucrat::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low");
}