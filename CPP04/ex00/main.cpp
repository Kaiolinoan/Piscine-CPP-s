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

    std::cout << "Type: "<< meta->getType() << " | Sound: ";
    meta->makeSound();
    std::cout << std::endl;

    std::cout << "Type: "<< d->getType() << " | Sound: ";
    d->makeSound();
    std::cout << std::endl;
    
    std::cout << "Type: "<< c->getType() << " | Sound: ";
    c->makeSound();
    std::cout << std::endl;

    std::cout << "Type: "<< Wa->getType() << " | Sound: ";
    Wa->makeSound();
    std::cout << std::endl;
    
    std::cout << "Type: "<< Wc->getType() << " | Sound: ";
    Wc->makeSound();
    std::cout << std::endl;
    meta->makeSound();

    c = d;
    return 0;
}