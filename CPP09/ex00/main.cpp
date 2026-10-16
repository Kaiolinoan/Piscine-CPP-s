#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (std::cout << "Error: Program expects an argument!\n", -1);
    else if (argc > 2)
        return (std::cout << "Error: Program just accept one argument!\n", -1);
    BitcoinExchange btc(argv[1]);
    btc.run();
}