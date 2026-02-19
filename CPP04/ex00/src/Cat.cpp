#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat deafult constructor called\n";
}

Cat::Cat(const Cat& other) : Animal()
{
    this->type = other.type;
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}
void Cat::makeSound() const
{
    std::cout << "Cat meows\n";
}