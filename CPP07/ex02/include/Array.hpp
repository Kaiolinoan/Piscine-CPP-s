#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
template <typename T>
class Array
{
    private:
        T* arr;
        unsigned int len;
    public:
        //CONSTRUCTORS AND DESTRUCTOR
        ~Array();
        Array();
        Array(const unsigned int &n);
        Array(const Array& other);

        //OPERATORS
        Array& operator=(const Array& other);
        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;

        // METHODS
        unsigned int size() const;

        //EXCEPTIONS
        class InvalidIndex: public std::exception
        {
            const char* what() const throw();
        };
};
#include "../src/Array.tpp"
#endif