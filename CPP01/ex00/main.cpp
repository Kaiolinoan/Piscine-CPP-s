#include "Zombie.hpp"

int main (void)
{
    Zombie *z1;

    z1 = newZombie("Test1");
    randomChump("Test2");
    delete z1;
}