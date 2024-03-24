#include "Cure.hpp"

Cure::Cure()
	: AMateria(std::string("cure")) {};

Cure::Cure(const Cure& copy)
	: AMateria(copy.type) {};

Cure& Cure::operator=(const Cure& copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

Cure::~Cure() {};

AMateria* Cure::clone() const
{	
	try
	{
		AMateria *cure = new Cure();
		return (cure);
	}
	catch(const std::bad_alloc& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
