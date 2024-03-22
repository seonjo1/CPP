#include "Cat.hpp"

Cat::Cat()
    : Animal(std::string("Cat"))
{
    brain = new Brain();
    std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& copy)
    : Animal(copy)
{
    brain = new Brain(*(copy.brain));
    std::cout << "Cat constructor called\n";
}

Cat& Cat::operator=(const Cat& copy)
{
    if (this != &copy)
    {
        type = copy.type;
        *brain = *(copy.brain);
    }
    return (*this);
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow~\n";
}
