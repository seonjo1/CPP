#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    {
        std::cout << "subject test\n\n";
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j; //should not create a leak
        delete i;
    }

    {
        std::cout << "\n\narray test\n\n";

        Animal *animal[6];
        
        std::cout << "Dog\n";
        animal[0] = new Dog();
        animal[1] = new Dog(*(dynamic_cast<Dog*>(animal[0])));
        animal[2] = new Dog();
        *(dynamic_cast<Dog*>(animal[2])) = *(dynamic_cast<Dog*>(animal[0]));
        
        std::cout << "\nCat\n";
        animal[3] = new Cat();
        animal[4] = new Cat(*(dynamic_cast<Cat*>(animal[3])));
        animal[5] = new Cat();
        *(dynamic_cast<Cat*>(animal[5])) = *(dynamic_cast<Cat*>(animal[3]));

        std::cout << "\nMake sound\n";
        for (int i = 0; i < 6; i++)
            animal[i]->makeSound();
        
        std::cout << "\nDelete\n";
        for (int i = 0; i < 6; i++)
            delete animal[i];
    }
    return 0;
}
