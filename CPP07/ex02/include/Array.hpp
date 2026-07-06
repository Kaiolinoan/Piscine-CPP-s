#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include "InvalidIndexException.hpp"
template <typename T>
class Array
{
    private:
        T* arr;
        unsigned int len;
    public:
        ~Array();
        Array();
        Array(const unsigned int &n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;
        unsigned int size() const;
};
#include "../src/Array.tpp"
#endif