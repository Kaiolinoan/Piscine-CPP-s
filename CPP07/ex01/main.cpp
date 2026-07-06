#include "Iter.hpp"

int main()
{
    size_t len = 3;

    std::cout << "===============STR============\n";
    std::string arr1[len] = {"ola", "hey", "hi"};
    ::iter(arr1, len, print);
    ::iter(arr1, len, addDot);
    std::cout << "\nAfter addDot():\n";
    ::iter(arr1, len, print);
    
    std::cout << "===============INT============\n";
    int arr2[len] = {80, 70, 50};
    ::iter(arr2, len, print);
    ::iter(arr2, len, increment);
    std::cout << "\nAfter increment():\n";
    ::iter(arr2, len, print);
    
    std::cout << "===============DOUBLE============\n";
    double arr3[len] = {10.5, 6.7, 8.6};
    ::iter(arr3, len, print);
    ::iter(arr3, len, increment);
    std::cout << "\nAfter increment():\n";
    ::iter(arr3, len, print);
}