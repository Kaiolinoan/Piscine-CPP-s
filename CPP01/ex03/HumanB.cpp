#include "HumanB.hpp"

HumanB::HumanB(std::string new_name) : name(new_name), humanB_weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack()
{
    if (humanB_weapon)
        std::cout << name << " attacks with their " << humanB_weapon->getType() << "\n";
}
void HumanB::setWeapon(Weapon &new_weapon)
{
    humanB_weapon = &new_weapon;
}

