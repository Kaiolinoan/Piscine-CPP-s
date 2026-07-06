#include "GradeTooLowException.hpp"

GradeTooLowException::GradeTooLowException() : _message("Grade is too low.") {};

const char* GradeTooLowException::what() const throw() {return _message.c_str();}



