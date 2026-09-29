#include "EmptySpanException.hpp"

EmptySpan::EmptySpan() : _message("Span is empty!") {};

const char* EmptySpan::what() const throw() {return _message.c_str();}