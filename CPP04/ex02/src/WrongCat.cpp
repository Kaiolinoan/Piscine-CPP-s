#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat deafult constructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal()
{
    this->type = other.type;
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}
void WrongCat::makeSound() const
{
    std::cout << "WrongCat speaks\n";
}