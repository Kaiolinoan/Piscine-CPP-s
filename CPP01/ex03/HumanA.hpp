#include "Weapon.hpp"
#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
class HumanA
{
    private:
        std::string name;
        Weapon      &humanA_weapon;
    public:
        HumanA(std::string new_name, Weapon &new_weapon);
        ~HumanA();
        void attack();
};
#endif
