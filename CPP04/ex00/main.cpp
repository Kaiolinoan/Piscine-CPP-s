#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"
#include "includes/Dog.hpp"

int main ()
{
    const WrongAnimal* Wa = new WrongAnimal();
    const WrongAnimal* Wc = new WrongCat();
    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    std::cout << d->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    std::cout << Wc->getType() << " " << std::endl;
    
    meta->makeSound();
    d->makeSound();
    c->makeSound();
    Wa->makeSound();
    Wc->makeSound();
    return 0;
}