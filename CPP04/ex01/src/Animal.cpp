#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Animal copy constructor called\n";
}
Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (type);
}

void Animal::makeSound() const
{
    std::cout << "Animal made a sound\n";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}