#include "Span.hpp"

Span::~Span() {}

Span::Span() : max_size(0) {}

Span::Span(const unsigned int& nb) : max_size(nb) {}

Span::Span(const Span& other) : max_size(other.max_size), numbers(other.numbers) {}

Span& Span::operator=(const Span& other) 
{
    if (this != &other)
    {
        this->numbers = other.numbers; 
        this->max_size = other.max_size;
    }
    return (*this);
}

void Span::addNumber(int number)
{
    if (numbers.size() == this->max_size)
        throw FullSpan();
    numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    size_t count = std::distance(begin, end);
    if (numbers.size() + count > this->max_size)
        throw FullSpan();
    
    while(begin != end)
    {
        this->numbers.push_back(*begin);
        ++begin;
    }
}

int Span::longestSpan()
{
    if (numbers.size() <= 1)
        throw EmptySpan();

    std::vector<int>::iterator min = std::min_element(numbers.begin(), numbers.end());
    std::vector<int>::iterator max = std::max_element(numbers.begin(), numbers.end());
    return (*max - *min);
}

int Span::shortestSpan()
{
    if (numbers.size() <= 1)
        throw EmptySpan();

    std::vector<int> copy = this->numbers;
    std::vector<int> storage;

    std::sort(copy.begin(), copy.end());
    for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
    {
        if ((it + 1) != copy.end())
        {
            int val = *(it + 1) - *it;
            storage.push_back(val);
        }
    }
    std::vector<int>::iterator min = std::min_element(storage.begin(), storage.end());
    return (*min);
}
