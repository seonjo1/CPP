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
	try
	{
		AMateria *ice = new Ice();
		return (ice);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
