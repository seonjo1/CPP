#include "AMateria.hpp"

AMateria::AMateria() {};

AMateria::AMateria(std::string const & type)
	: type(type) {};

AMateria::AMateria(const AMateria& copy)
	: type(copy.type) {};

AMateria& AMateria::operator=(const AMateria& copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

AMateria::~AMateria() {};

std::string const & AMateria::getType() const
{
	return (type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* this skill is invaild to " << target.getName() << "*\n";
}
