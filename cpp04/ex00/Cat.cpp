#include "Cat.hpp"

Cat::Cat()
	: Animal(std::string("Cat"))
{
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat& copy)
	: Animal(copy)
{
	std::cout << "Cat constructor called\n";
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Meow~\n";
}
