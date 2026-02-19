#include "Weapon.hpp"
#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
class HumanB
{
    private:
        std::string name;
        Weapon      *humanB_weapon;
    public:
        HumanB(std::string new_name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &new_weapon);
};
#endif