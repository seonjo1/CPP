#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(std::string type)
	: type(type)
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal& copy)
	: type(copy.type)
{
	std::cout << "Animal constructor called\n";
}

Animal& Animal::operator=(const Animal& copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

const std::string& Animal::getType() const
{
	return (type);
}
