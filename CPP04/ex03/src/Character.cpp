#include "Character.hpp"

Character::Character(std::string name) : name(name) 
{
    for (size_t i = 0; i < 4; i++)
        inventory[i]=NULL;
}

Character::Character(const Character& other) : name (other.name)
{
    for (size_t i = 0; i < 4; i++)
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->name = other.name;
        for (size_t i = 0; i < 4; i++)
        {
            if (this->inventory[i])
            {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (name);    
}

void Character::equip(AMateria* m)
{
    for(size_t i = 0; i < 4; i++)
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return;
        }
}
void Character::unequip(int idx)
{
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (inventory[idx] != NULL)
        inventory[idx]->use(target);
}

Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
        if (inventory[i])
            delete inventory [i];
}


