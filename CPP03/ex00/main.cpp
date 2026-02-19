#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap a("BATMAN");
    ClapTrap b(a);
    ClapTrap c("BATCAR");

    a.attack("JOKER");
    b.attack("JOKER");
    c.attack("JOKER");
    
    b = c;

    b.attack("JOKER");
    a.takeDamage(5);
    a.beRepaired(10);
}