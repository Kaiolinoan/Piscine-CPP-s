#include "whatever.hpp"

int main()
{
    int x = 5;
    int y = 10;
    std::cout << "===============INT============\n";
    std::cout << "Min result: " << ::min(x, y) << "\n";
    std::cout << "Max result: " << ::max(x, y) << "\n";
    std::cout << "Before swap:\nx: " << x << " y: " << y << "\n";
    ::swap(x, y);
    std::cout << "After swap:\nx:" << x << " y: " << y << "\n";

    std::cout << "===============STRING============\n";
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    std::cout << "Min result: " << ::min(c, d) << "\n";
    std::cout << "Max result: " << ::max(c, d) << "\n";
    std::cout << "Before swap:\nc: " << c << " d: " << d << "\n";
    ::swap(c, d);
    std::cout << "After swap:\nc: " << c << " d: " << d << "\n";
}