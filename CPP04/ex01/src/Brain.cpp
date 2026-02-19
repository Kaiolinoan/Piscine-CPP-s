#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& other) : ideas(other.ideas)
{
    std::cout << "Brain copy constructor called\n";
}
void Brain::setIdea(size_t index, std::string content)
{
    ideas[index] = content;
}
std::string Brain::getIdeaAt(size_t index) const
{
    return (ideas[index]);
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}