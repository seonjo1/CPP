#include "Dog.hpp"

Dog::Dog()
	: Animal(std::string("Dog"))
{
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog& copy)
	: Animal(copy)
{
	std::cout << "Dog constructor called\n";
}

Dog& Dog::operator=(const Dog& copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Woof!\n";
}
