#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog deafult constructor called\n";
}

Dog::Dog(const Dog& other) : Animal()
{
    this->type = other.type;
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}
void Dog::makeSound() const
{
    std::cout << "Dog barks\n";
}