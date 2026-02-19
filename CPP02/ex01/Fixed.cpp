#include "Fixed.hpp"

Fixed::Fixed(): value(0) 
{
    std::cout << "Calling constructor\n";
}

Fixed::Fixed(const Fixed& other) : value(other.getRawBits())
{
    std::cout << "Calling copy constructor\n";
}
Fixed::Fixed(const int n ) : value(n << decimalBits) 
{
    std::cout << "Calling constructor with a const int as parameter\n";
}

Fixed::Fixed(const float n ) : value(roundf(n * (1 << decimalBits))) 
{
    std::cout << "Calling constructor with a float int as parameter\n";
}

int Fixed::toInt( void ) const
{
    return (value >> decimalBits);
}

float Fixed::toFloat( void ) const
{
    return ((float)value / (1 << decimalBits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Assignement operator called\n";
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed() 
{
    std::cout << "Calling destructor\n";
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits function called\n"; 
    return(value);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits function called\n"; 
    value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& object)
{
    out << object.toFloat();
    return (out);
}