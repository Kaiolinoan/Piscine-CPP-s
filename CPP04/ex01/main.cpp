#include "includes/Cat.hpp"
#include "includes/WrongCat.hpp"
#include "includes/Dog.hpp"

int main()
{   
    Dog a;
    a.getBrain()->setIdea(0, "Dog's first idea");
    Dog b = a;
    b.getBrain()->setIdea(0, "Dog's second idea");
    Dog c;
    c = a;
    
    Cat x;
    x.getBrain()->setIdea(0, "Cat's first  idea");
    Cat y = x;
    y.getBrain()->setIdea(0, "Cat's second idea");
    Cat z;
    z = x;
    
    std::cout << "-----Deep copy test: ------" << std::endl;
    std::cout << a.getBrain()->getIdeaAt(0) << "\n";
    std::cout << b.getBrain()->getIdeaAt(0) << "\n";
    std::cout << c.getBrain()->getIdeaAt(0) << "\n";

    std::cout << x.getBrain()->getIdeaAt(0) << "\n";
    std::cout << y.getBrain()->getIdeaAt(0) << "\n";
    std::cout << z.getBrain()->getIdeaAt(0) << "\n";
    std::cout << "------------------------------" << std::endl;

    Animal* array[10];
    for (size_t i = 0; i < 5; i++)
    array[i] = new Dog();
    for (size_t i = 5; i < 10; i++)
    array[i] = new Cat();
    std::cout << "-----Polymorphism test: ------" << std::endl;
    for (size_t i = 0; i < 10; i++)
        array[i]->makeSound();
    std::cout << "------------------------------" << std::endl;
    for (size_t i = 0; i < 10; i++)
        delete array[i];
    return 0;
    
}
