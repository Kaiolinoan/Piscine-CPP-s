#include "Serialization.hpp"

int main()
{
    {
        Data d;
        uintptr_t raw = Serialization::serialize(&d);
        Data *new_d = Serialization::deserialize(raw);

        std::cout << "================ADDRESS===============\n";
        if (new_d == &d)
            std::cout << "Success!\nSame Address\n";
        else
            std::cout << "Failed!\nDifferent Addresses\n";
    }

    {
        std::cout << "================VALUE===============\n";
        Data t;
        int value = 42;
        t.value = value;
        uintptr_t raw = Serialization::serialize(&t);
        Data *new_t = Serialization::deserialize(raw);

        if (new_t == &t && new_t->value == value) 
            std::cout << "Success!\nSame Value\n";
        else
            std::cout << "Failed!\nDifferent Value\n";
    }
}