#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (std::cerr << "Error: Program execpects arguments" << std::endl, -1);
    else if (argc > 2)
        return (std::cerr << "Error: Program supports only one argument" << std::endl, -1);
    RPN rpn;

    if (!rpn.calculate(argv[1]))
        return (-1);
}