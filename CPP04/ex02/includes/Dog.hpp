#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Dog: virtual public A_Animal
{
    private:
        Brain* Bptr;
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        void makeSound() const;
        Brain* getBrain() const;
        ~Dog();
};
#endif


