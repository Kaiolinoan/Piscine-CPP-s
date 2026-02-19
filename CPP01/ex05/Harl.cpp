#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void )
{
    std::cout << "Debugging.\n";
}
void Harl::info( void )
{
    std::cout << "Showing an information.\n";
}
void Harl::warning( void )
{
    std::cout << "Warning.\n";
}
void Harl::error( void )
{
    std::cout << "Showing an error.\n";
}

void Harl::complain( std::string level )
{
    typedef void (Harl::*HarlFunc)();
    HarlFunc arrayFunc[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string arrayLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++)
    {
        if (arrayLevels[i] == level)
        {
            (this->*arrayFunc[i])();
            return;
        }
    }
    std::cout << "Harl has nothing to complain about.\n";
}