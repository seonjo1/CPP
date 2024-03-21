#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	full_hp = 100;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + std::string("_clap_name")), name(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 30;
	full_hp = 100;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
	: ScavTrap(obj)
{
	DiamondTrap::name = obj.name;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this != &obj)
	{
		name = obj.name;
		ScavTrap::operator=(obj);
	}
	return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << name << 
		" ClapTrap name : " << ClapTrap::name << std::endl;
}
