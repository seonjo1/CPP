#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
        // Animal* animal = new Animal();
        // delete animal;
    }
    
    {
        std::cout << "Dog test\n";
        Animal* animal = new Dog();
        animal->makeSound();
        delete animal;
    }

    {
        std::cout << "\nCat test\n";
        Animal* animal = new Cat();
        animal->makeSound();
        delete animal;
    }
}
