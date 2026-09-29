#include "FullSpanException.hpp"

FullSpan::FullSpan() : _message("Span is full!") {};

const char* FullSpan::what() const throw() {return _message.c_str();}