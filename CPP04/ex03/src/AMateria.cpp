#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::AMateria() : type(NULL) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
    return (type);
}
