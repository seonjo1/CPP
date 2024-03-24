#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal(std::string("WrongCat"))
{
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& copy)
	: WrongAnimal(copy)
{
	std::cout << "WrongCat constructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& copy)
{
	if (this != &copy)
		type = copy.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << "Meow~\n";
}
