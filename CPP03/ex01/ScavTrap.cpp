#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called\n";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.name)
{
    std::cout << "ScavTrap copy constructor called\n";
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is in gate keeper mode!\n";
}

void ScavTrap::attack(const std::string& target)
{
    if (!HitPoints || !EnergyPoints)
        return ;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage <<" points of damage!\n";
    EnergyPoints--;
}