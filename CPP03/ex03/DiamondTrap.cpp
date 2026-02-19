#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
    std::cout << "DiamondTrap constructor called\n";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other.name + "_clap_name"), FragTrap(other.name), ScavTrap(other.name), name(other.name)
{
    std::cout << "DiamondTrap copy constructor called\n";
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap's name: " << this->name << "\n";
    std::cout << "ClapTrap's name: " << ClapTrap::name << "\n"; 
}   