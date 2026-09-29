#include <MutantStack.hpp>

int main()
{
    MutantStack<int> ms;

    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);

    for (std::stack<int>::container_type::iterator it = ms.begin(); it != ms.end(); ++it)
    {
        std::cout << *it << std::endl;
        ms.pop();
    }


    std::cout << "\nAFTER ERASE\n";

    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    ms.push(50);

    for (std::stack<int>::container_type::iterator it = ms.begin(); it != ms.end(); ++it)
    {
        std::cout << *it << std::endl;
        ms.pop();
    }

}