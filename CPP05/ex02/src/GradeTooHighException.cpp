#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException() : _message("Grade is too high.") {};

const char* GradeTooHighException::what() const throw() {return _message.c_str();}



