#include <iostream>
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
class Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void announce(void);
        void set_name(const std::string& new_name);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif