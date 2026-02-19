#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <fstream>


class Fixed
{
    private:
        int value;
        static const int decimalBits = 8;
    public:
        ~Fixed                  ();
        Fixed                   ();
        Fixed                   (const int n);
        Fixed                   (const float n);
        Fixed                   (const Fixed& other);
        int                     toInt( void ) const;
        float                   toFloat( void ) const;
        int                     getRawBits( void ) const;
        void                    setRawBits( int const raw );
        static Fixed&           min(Fixed& a, Fixed& b);
        static Fixed&           max(Fixed& a, Fixed& b);
        static const Fixed&     min(const Fixed& a, const Fixed& b);
        static const Fixed&     max(const Fixed& a, const Fixed& b);
        Fixed&                  operator=(const Fixed& other);
        Fixed                   operator+(const Fixed& other);  
        Fixed                   operator-(const Fixed& other);  
        Fixed                   operator*(const Fixed& other);  
        Fixed                   operator/(const Fixed& other);  
        bool                    operator<(const Fixed& other) const;
        bool                    operator>(const Fixed& other) const;
        bool                    operator>=(const Fixed& other) const;
        bool                    operator<=(const Fixed& other) const;
        bool                    operator==(const Fixed& other) const;
        bool                    operator!=(const Fixed& other) const;
        Fixed&                  operator++();  
        Fixed&                  operator--();  
        Fixed                   operator++(int);  
        Fixed                   operator--(int);  
};

std::ostream& operator<<(std::ostream& out, const Fixed& object);

#endif
