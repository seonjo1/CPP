#include "Cat.hpp"

Cat::Cat()
    : Animal(std::string("Cat"))
{
    try
    {
        brain = new Brain();
        std::cout << "Cat constructor called\n";
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
}

Cat::Cat(const Cat& copy)
    : Animal(copy)
{
    try
    {
        brain = new Brain(*(copy.brain));
        std::cout << "Cat constructor called\n";
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(EXIT_FAILURE);
    }
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
