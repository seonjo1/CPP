#include "FragTrap.hpp"

FragTrap::FragTrap()
	: ClapTrap(100, 100, 30)
{
	std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called\n";
}

FragTrap::FragTrap(const FragTrap& obj)
	: ClapTrap(obj)
{
	std::cout << "FragTrap constructor called\n";	
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	return (*this);
}

void FragTrap::highFivesGuy()
{
	std::cout << "FragTrap " << name << " request a positive high fives\n";
}
