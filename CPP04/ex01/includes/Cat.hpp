#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: virtual public Animal
{
    private:
        Brain* Bptr;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        Brain* getBrain() const;
        void makeSound() const ;
        ~Cat();
};
#endif

