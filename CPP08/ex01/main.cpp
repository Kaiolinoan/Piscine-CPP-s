#include "Span.hpp"
#include <iostream>
#include <ctime>
int main()
{
    std::srand(std::time(NULL));

    try{
        std::cout << "======== NORMAL SPAN TEST =========\n";
        Span nb(5);
        
        nb.addNumber(5);
        nb.addNumber(6);
        nb.addNumber(7);
        nb.addNumber(8);
        nb.addNumber(9);

        std::cout << "Valid Span!\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        std::cout << "======== FULL SPAN TEST =========\n";
        Span nb(5);
        
        nb.addNumber(5);
        nb.addNumber(6);
        nb.addNumber(7);
        nb.addNumber(8);
        nb.addNumber(9);
        nb.addNumber(10);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        std::cout << "======== VALID METHODS TEST =========\n";
        Span nb(5);
        
        nb.addNumber(10);
        nb.addNumber(20);
        nb.addNumber(50);
        nb.addNumber(110);
        nb.addNumber(15);

        std::cout << "Longest span is: " << nb.longestSpan() << "\n";
        std::cout << "Shortest span is: " << nb.shortestSpan() << "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        std::cout << "======== INVALID LONGEST SPAN TEST =========\n";
        Span nb(1);
        
        nb.addNumber(10);

        std::cout << "Longest span is: " << nb.longestSpan() << "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try{
        std::cout << "======== INVALID SHORTEST SPAN TEST =========\n";
        Span nb(1);
        
        nb.addNumber(10);

        std::cout << "Shortest span is: " << nb.shortestSpan() << "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "======== BIG RANGE VALID TEST =========\n";
        std::vector<int> vec;

        for (int i = 0; i < 10000; i++)
            vec.push_back(std::rand());

        Span sp(10000);
        sp.addNumber(vec.begin(), vec.end());
        std::cout << "Shortest span is: " << sp.shortestSpan() << "\n";
        std::cout << "Longest span is: " << sp.longestSpan() << "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "======== BIG RANGE INVALID TEST =========\n";
        std::vector<int> vec;

        for (int i = 0; i < 10000; i++)
            vec.push_back(std::rand());

        Span sp(10000);
        sp.addNumber(10);
        sp.addNumber(vec.begin(), vec.end());
        std::cout << "Shortest span is: " << sp.shortestSpan() << "\n";
        std::cout << "Longest span is: " << sp.longestSpan() << "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "======== OPERATOR AND COPY TEST =========\n";
        Span nb(5);
        
        nb.addNumber(10);
        nb.addNumber(20);
        nb.addNumber(50);
        nb.addNumber(110);
        nb.addNumber(15);

        Span copy(nb);

        Span sp(5);
        sp = copy;
        std::cout << "Shortest span is: " << sp.shortestSpan() << "\n";
        std::cout << "Longest span is: " << sp.longestSpan() << "\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}