#include "FormNotSignedException.hpp"

FormNotSignedException::FormNotSignedException() : _message("Form is not signed") {};

const char* FormNotSignedException::what() const throw() {return _message.c_str();}
