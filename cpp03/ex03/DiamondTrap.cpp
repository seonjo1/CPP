#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	hit_points = FragTrap::F_hit_points;
	energy_points = ScavTrap::S_energy_points;
	attack_damage = FragTrap::F_attack_damage;
	full_hp = FragTrap::F_hit_points;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + std::string("_clap_name")), name(name)
{
	hit_points = FragTrap::F_hit_points;
	energy_points = ScavTrap::S_energy_points;
	attack_damage = FragTrap::F_attack_damage;
	full_hp = FragTrap::F_hit_points;
	std::cout << "DiamondTrap constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
	: ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
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
