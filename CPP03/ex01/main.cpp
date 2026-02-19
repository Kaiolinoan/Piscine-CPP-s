#include "ScavTrap.hpp"

int main (void)
{
    ScavTrap a("ROBOT");
    ScavTrap b("BOT");
    ScavTrap c(a);
    
    a.attack("IRON MAN");
    b.attack("IRON MAN");
    c.attack("IRON MAN");

    c = b;

    a.guardGate();
    b.guardGate();
    c.guardGate();
}