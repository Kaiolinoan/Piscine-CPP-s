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
		this->_grade = other.get_grade();
	}
	return (*this);
};

std::string Bureaucrat::get_name() const { return (this->_name); }

int         Bureaucrat::get_grade() const { return (this->_grade); }

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object)
{
	out << object.get_name() << ", bureaucrat grade " << object.get_grade() << "\n";
	return (out);
}
