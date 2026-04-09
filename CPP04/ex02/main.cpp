#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"
#include "includes/Dog.hpp"

int main ()
{
    // A_Animal animal;

    A_Animal* array[10];
    for (size_t i = 0; i < 5; i++)
        array[i] = new Dog();
    for (size_t i = 5; i < 10; i++)
        array[i] = new Cat();
    for (size_t i = 0; i < 10; i++)
        delete array[i];
    return 0;
}