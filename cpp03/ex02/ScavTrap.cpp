#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
	: ClapTrap(100, 50, 20), guardGatemode(false)
{
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(std::string name)
	: ClapTrap(name, 100, 50, 20), guardGatemode(false)
{
	std::cout << "ScavTrap constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& obj)
	: ClapTrap(obj), guardGatemode(obj.guardGatemode)
{
	std::cout << "ScavTrap constructor called\n";	
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		guardGatemode = obj.guardGatemode;
	}
	return (*this);
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
		std::cout << "ScavTrap " << name << " is already broken\n";
	else if (energy_points > 0)
	{
		energy_points--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing ";
		std::cout << attack_damage << " points of damage!\n";
	}
	else
		std::cout << "ScavTrap " << name << " lacks energy\n";
}

void ScavTrap::guardGate()
{
	guardGatemode = true;
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode\n";
}
