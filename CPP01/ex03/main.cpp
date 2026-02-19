#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(std::string new_type) : type (new_type) {}

Weapon::~Weapon() {}

void Weapon::setType(const std::string& newType) 
{
    type = newType;
}

std::string Weapon::getType() const
{
    return (type);
}

int main(void)
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;

}