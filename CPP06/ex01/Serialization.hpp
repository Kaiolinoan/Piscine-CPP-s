#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>
#include <iostream>
#include "Data.h"
class Serialization 
{
    private:
        ~Serialization();
        Serialization();
        Serialization(const Serialization& other);
        Serialization& operator=(const Serialization& other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif