#include "Dog.hpp"

Dog::Dog()
    : Animal(std::string("Dog"))
{
    try
    {
        brain = new Brain();
        std::cout << "Dog constructor called\n";
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}

Dog::Dog(const Dog& copy)
    : Animal(copy)
{    
    try
    {
        brain = new Brain(*(copy.brain));
        std::cout << "Dog constructor called\n";
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
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
