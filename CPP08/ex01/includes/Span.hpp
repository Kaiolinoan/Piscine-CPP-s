#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include "EmptySpanException.hpp"
#include "FullSpanException.hpp"

class Span
{
    private:
        unsigned int max_size;
        std::vector<int> numbers;
    public:
        Span();
        ~Span();
        Span(const unsigned int& nb);
        Span(const Span &other);
        Span& operator=(const Span &other);
        void addNumber(int number);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};

#endif