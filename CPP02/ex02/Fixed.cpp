#include "Fixed.hpp"
//CONSTRUCTORS

Fixed::Fixed(): value(0) 
{
    // std::cout << "Calling constructor\n";
}

Fixed::Fixed(const Fixed& other) : value(other.getRawBits())
{
    // std::cout << "Calling copy constructor\n";
}
Fixed::Fixed(const int n ) : value(n << decimalBits) 
{
    // std::cout << "Calling constructor with a const int as parameter\n";
}

Fixed::Fixed(const float n ) : value(roundf(n * (1 << decimalBits))) 
{
    // std::cout << "Calling constructor with a float int as parameter\n";
}

// OPERATORS

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Assignement operator called\n";
    if (this != &other)
        this->value = other.getRawBits();
    return (*this);
}

Fixed Fixed::operator+(const Fixed& other)
{
    Fixed temp = this->toFloat() + other.toFloat();
    return (temp);
}

Fixed Fixed::operator-(const Fixed& other)
{
    Fixed temp = this->toFloat() - other.toFloat();
    return (temp);
}

Fixed Fixed::operator*(const Fixed& other)
{
    Fixed temp = this->toFloat() * other.toFloat();
    return (temp);
}

Fixed Fixed::operator/(const Fixed& other)
{
    Fixed temp = this->toFloat() / other.toFloat();
    return (temp);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->value < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->value > other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->value != other.getRawBits());
}

Fixed& Fixed::operator++()
{
    this->value++;
    return(*this);
}

Fixed& Fixed::operator--()
{
    this->value--;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->value++;
    return(temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->value--;
    return(temp);
}

std::ostream& operator<<(std::ostream& out, const Fixed& object)
{
    out << object.toFloat();
    return (out);
}

//GETTERS AND SETTERS

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits function called\n"; 
    return(value);
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits function called\n"; 
    value = raw;
}

// CONVERSIONS

int Fixed::toInt( void ) const
{
    return (value >> decimalBits);
}

float Fixed::toFloat( void ) const
{
    return ((float)value / (1 << decimalBits));
}
//MIN AND MAX
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}


// DESTRUCTOR

Fixed::~Fixed() 
{
    // std::cout << "Calling destructor\n";
}