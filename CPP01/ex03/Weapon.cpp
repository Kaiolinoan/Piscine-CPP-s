#include "Weapon.hpp"

Weapon::Weapon(std::string new_type) : type (new_type) {}

Weapon::~Weapon() {}

void Weapon::setType(const std::string& newType) 
{
    type = newType;
}

const std::string& Weapon::getType() const
{
    return (type);
}