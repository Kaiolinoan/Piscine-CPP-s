#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

class Span
{
    private:
        unsigned int max_size;
        std::vector<int> numbers;
    public:
        //CONSTRUCTORS AND DESTRUCOT
        Span();
        ~Span();
        Span(const unsigned int& nb);
        Span(const Span &other);

        //OPERATOR
        Span& operator=(const Span &other);
        
        //METHODS
        void addNumber(int number);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        //EXCEPTIONS
        class EmptySpan: public std::exception
        {
            const char* what() const throw();
        };
        class FullSpan: public std::exception
        {
            const char* what() const throw();
        };
};

#endif