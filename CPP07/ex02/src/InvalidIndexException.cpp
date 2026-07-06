#include "InvalidIndexException.hpp"

InvalidIndex::InvalidIndex() : _message("Invalid Index.") {};

const char* InvalidIndex::what() const throw() {return _message.c_str();}



