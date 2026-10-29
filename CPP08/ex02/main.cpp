#include <MutantStack.hpp>

int main()
{
    MutantStack<int> ms;

    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);

    std::cout << "=====================NORMAL ITERATOR================" << std::endl;
    for (std::stack<int>::container_type::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "=====================CONST ITERATOR================" << std::endl;
    MutantStack<int> const_ms(ms);
    for (std::stack<int>::container_type::const_iterator it = const_ms.begin(); it != const_ms.end(); ++it)
        std::cout << *it << std::endl;
    
    std::cout << "=====================REVERSE ITERATOR================" << std::endl;
    MutantStack<int> r_ms = ms;
    for (std::stack<int>::container_type::reverse_iterator it = r_ms.rbegin(); it != r_ms.rend(); ++it)
        std::cout << *it << std::endl;

    std::cout << "=====================CONST REVERSE ITERATOR================" << std::endl;
    MutantStack<int> const_r_ms(ms);
    for (std::stack<int>::container_type::const_reverse_iterator it = const_r_ms.rbegin(); it != const_r_ms.rend(); ++it)
        std::cout << *it << std::endl;
    
}