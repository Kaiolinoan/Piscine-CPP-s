#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &new_weapon) : name(new_name), humanA_weapon(new_weapon) {}

HumanA::~HumanA() {}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << humanA_weapon.getType() << "\n";
}

