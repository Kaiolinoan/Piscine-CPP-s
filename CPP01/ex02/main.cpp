#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN\n";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Var address: " << &str << "\n";
    std::cout << "Pointer address: " << stringPTR << "\n";
    std::cout << "Reference address: " << &stringREF << "\n";

    std::cout << "\n";
    
    std::cout << "Var value: " << str;
    std::cout << "Pointer value: " << *stringPTR;
    std::cout << "Reference value: " << stringREF;
}