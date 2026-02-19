#include "DiamondTrap.hpp"

int main (void)
{
    DiamondTrap a("AVENGERS");
    DiamondTrap b("MARVEL");
    DiamondTrap c(a);
    
    
    a.attack("THANOS");
    b.attack("THANOS");
    c.attack("THANOS");
    c = b;
    a.whoAmI();
    b.whoAmI();
    c.whoAmI();
}