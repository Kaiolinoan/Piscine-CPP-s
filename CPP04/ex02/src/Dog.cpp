#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    this->Bptr = new Brain();
    std::cout << "Dog deafult constructor called\n";
}

Dog::Dog(const Dog& other) : A_Animal()
{
    Bptr = new Brain(*other.Bptr);
    this->type = other.type;
    std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {   
        delete Bptr;
        Bptr = new Brain(*other.Bptr);
        this->type = other.type;
    }
    return (*this);
}

Brain* Dog::getBrain() const
{
    return Bptr;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete Bptr;
}
void Dog::makeSound() const
{
    std::cout << "Dog barks\n";
}