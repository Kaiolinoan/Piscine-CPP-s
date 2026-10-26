#include "whatever.hpp"

int main()
{
    int int1 = 5;
    int int2 = 10;
    std::cout << "===============INT============\n";
    std::cout << "Int1: " << int1 << " int2: " << int2 << "\n";
    std::cout << "Min result: " << ::min(int1, int2) << "\n";
    std::cout << "Max result: " << ::max(int1, int2) << "\n";
    std::cout << "Before swap:\nint1: " << int1 << " int2: " << int2 << "\n";
    ::swap(int1, int2);
    std::cout << "After swap:\nint1: " << int1 << " int2: " << int2 << "\n";

    float float1 = 6.7;
    float float2 = 7.6;
    std::cout << "===============FLOAT============\n";
    std::cout << "Float1: " << float1 << " float2: " << float2 << "\n";
    std::cout << "Min result: " << ::min(float1, float2) << "\n";
    std::cout << "Max result: " << ::max(float1, float2) << "\n";
    std::cout << "Before swap:\nfloat1: " << float1 << " float2: " << float2 << "\n";
    ::swap(float1, float2);
    std::cout << "After swap:\nfloat1: " << float1 << " float2: " << float2 << "\n";


    char char1 = '4';
    char char2 = '2';
    std::cout << "===============CHAR============\n";
    std::cout << "Char1: " << char1 << " char2: " << char2 << "\n";
    std::cout << "Min result: " << ::min(char1, char2) << "\n";
    std::cout << "Max result: " << ::max(char1, char2) << "\n";
    std::cout << "Before swap:\nchar1: " << char1 << " char2: " << char2 << "\n";
    ::swap(char1, char2);
    std::cout << "After swap:\nchar1: " << char1 << " char2: " << char2 << "\n";

    std::cout << "===============STRING============\n";
    std::string str1 = "chaine1";
    std::string str2 = "chaine2";
    
    std::cout << "Str1: " << str1 << " str2: " << str2 << "\n";
    std::cout << "Min result: " << ::min(str1, str2) << "\n";
    std::cout << "Max result: " << ::max(str1, str2) << "\n";
    std::cout << "Before swap:\nstr1: " << str1 << " str2: " << str2 << "\n";
    ::swap(str1, str2);
    std::cout << "After swap:\nstr1: " << str1 << " str2: " << str2 << "\n";
}

// int a = 5;
// int b = 5;

// std::cout << (::min(a, b) == b) << std::endl;
// std::cout << (::max(a, b) == b) << std::endl;