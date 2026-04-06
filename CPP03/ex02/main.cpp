#include "FragTrap.hpp"

int main (void)
{
    FragTrap a("FRAGAS");
    FragTrap b("FRAGUINHAS");
    FragTrap c(a);
    ScavTrap d("ZE");
    ClapTrap e("JOSE");
    
    a.attack("SPIDER MAN");
    b.attack("SPIDER MAN");
    c.attack("SPIDER MAN");
    d.attack("SPIDER MAN");
    e.attack("SPIDER MAN");

    c = b;

    a.highFivesGuys();
    b.highFivesGuys();
    c.highFivesGuys();
}