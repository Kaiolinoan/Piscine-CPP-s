#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n"; 
}
void Zombie::set_name(const std::string& new_name)
{
    name = new_name;
    return;
}
Zombie::Zombie() : name("ZOMBIE") {}
Zombie::~Zombie() 
{
    std::cout << "Destroying: " << name << "\n";
}
