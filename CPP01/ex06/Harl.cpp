#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "Debugging.\n";
}
void Harl::info( void )
{
    std::cout << "[ INFO ]\n";
    std::cout << "Showing an information.\n";
}
void Harl::warning( void )
{
    std::cout << "[ WARNING ]\n";
    std::cout << "Warning.\n";
}
void Harl::error( void )
{
    std::cout << "[ ERROR ]\n";
    std::cout << "Showing an error.\n";
}

void Harl::complain( std::string level )
{   
    int index = -1;
    std::string arrayLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (size_t i = 0; i < 4; i++)
        if (arrayLevels[i] == level)
            index = i;

    switch (index)
    {
        case 3:
            this->error();
            break;
        case 2:
            this->warning();
            this->error();
            break;
        case 1:
            this->info();
            this->warning();
            this->error();
            break;
        case 0:
            this->debug();
            this->info();
            this->warning();
            this->error();
            break;
        default:
            std::cout << "Harl has nothing to complain about.\n";
            break;
    }
}