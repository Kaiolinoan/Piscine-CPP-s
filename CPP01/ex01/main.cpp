#include "Zombie.hpp"

int main (void)
{
    int n = 3;
    Zombie *Horde = zombieHorde(n, "zombie");
    for (int i = 0; i < n; i++)
        Horde[i].announce();
    delete [] Horde;
}