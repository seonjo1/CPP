#include "Dog.hpp"

Dog::Dog()
    : Animal(std::string("Dog"))
{
    brain = new Brain();
    std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& copy)
    : Animal(copy)
{
    brain = new Brain(*(copy.brain));
    std::cout << "Dog constructor called\n";
}

Dog& Dog::operator=(const Dog& copy)
{
   if (this != &copy)
    {
        type = copy.type;
        *brain = *(copy.brain);
    }
    return (*this);
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
