#include "Serialization.hpp"

int main()
{
    Data d;
    uintptr_t raw = Serialization::serialize(&d);
    Data *new_d = Serialization::deserialize(raw);

    if (new_d == &d)
        std::cout << "Success!\nSame Address\n";
    else
        std::cout << "Failed!\nDifferent Addresses\n";
}