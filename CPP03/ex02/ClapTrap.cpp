#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap constructor called\n";
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage)
{
    std::cout << "ClapTrap copy constructor called\n";
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
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

void ClapTrap::attack(const std::string& target)
{
    if (!HitPoints || !EnergyPoints)
        return ;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttackDamage <<" points of damage!\n";
    EnergyPoints--;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (!HitPoints || !EnergyPoints)
        return ;
    std::cout << "ClapTrap " << this->name << " repairs itselsef healing " << amount << " points of damage!\n";
    HitPoints += amount;
    EnergyPoints--;   
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!HitPoints || !EnergyPoints)
        return ;
    std::cout << "ClapTrap " << this->name << " receives " << amount << " points of damage!\n";
    HitPoints -= amount;
}