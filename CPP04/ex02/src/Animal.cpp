#include "Animal.hpp"

A_Animal::A_Animal()
{
    std::cout << "A_Animal default constructor called\n";
}

A_Animal::A_Animal(const A_Animal& other) : type(other.type)
{
    std::cout << "A_Animal copy constructor called\n";
}
A_Animal& A_Animal::operator=(const A_Animal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string A_Animal::getType() const
{
    return (type);
}

void A_Animal::makeSound() const
{
    std::cout << "A_Animal made a sound\n";
}

A_Animal::~A_Animal()
{
    std::cout << "A_Animal destructor called\n";
}