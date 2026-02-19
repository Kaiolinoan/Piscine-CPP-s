#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    this->Bptr = new Brain();
    std::cout << "Cat deafult constructor called\n";
}

Cat::Cat(const Cat& other) : Animal()
{
    this->type = other.type;
    this->Bptr = new Brain(*other.Bptr);
    std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        delete this->Bptr;
        this->Bptr = new Brain(*other.Bptr);
        this->type = other.type;
    }
    return (*this);
}

Brain* Cat::getBrain() const
{
    return Bptr;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete Bptr;
}
void Cat::makeSound() const
{
    std::cout << "Cat meows\n";
}