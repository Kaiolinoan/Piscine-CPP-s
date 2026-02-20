#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl h;
    std::string str = argv[1];
    if (argc != 2)
    {
        std::cout << "Harl does not accept this input. Try again!\n";
        return (1);
    }
    h.complain(str);
}