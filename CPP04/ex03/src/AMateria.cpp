#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria() : type(NULL) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {} 
    return *this;
}

std::string const & AMateria::getType() const
{
    return (type);
}
