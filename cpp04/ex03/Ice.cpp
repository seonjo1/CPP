#include "Ice.hpp"

Ice::Ice()
	: AMateria(std::string("ice")) {};

Ice::Ice(const Ice& copy)
	: AMateria(copy.type) {};

Ice& Ice::operator=(const Ice& copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

Ice::~Ice() {};

AMateria* Ice::clone() const
{
	AMateria *ice = new Ice();
    return (ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
