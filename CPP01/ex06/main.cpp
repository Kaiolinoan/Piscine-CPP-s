#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl h;
    if (argc != 2)
    {
        std::cout << "Harl does not accept this input. Try again!\n";
        return (1);
    }
    std::string str = argv[1];
    h.complain(str);
}