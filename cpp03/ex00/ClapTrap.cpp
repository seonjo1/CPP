#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: hit_points(10), energy_points(10), attack_damage(0), full_hp(10)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hit_points(10), energy_points(10), 
		attack_damage(0), full_hp(10)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: name(obj.name), hit_points(obj.hit_points), energy_points(obj.energy_points), 
		attack_damage(obj.attack_damage), full_hp(obj.full_hp)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		name = obj.name;
		hit_points = obj.hit_points;
		energy_points = obj.energy_points;
		attack_damage = obj.attack_damage;
		full_hp = obj.full_hp;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is already broken\n";
	else if (energy_points > 0)
	{
		energy_points--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing ";
		std::cout << attack_damage << " points of damage!\n";
	}
	else
		std::cout << "ClapTrap " << name << " lacks energy\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= 4000000000)
		std::cout << name << "'s takeDamage amount is invalid\n";
	else if (hit_points == 0)
		std::cout << "ClapTrap " << name << " is already broken\n";
	else
	{
		if (hit_points <= amount)
		{
			hit_points = 0;
			std::cout << "ClapTrap " << name << " is broken\n";
		}
		else
		{
			hit_points -= amount;
			std::cout << "ClapTrap " << name << " suffered " << amount << " damage\n";
		}
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount >= 4000000000)
		std::cout << name << "'s beRepaired amount is invalid\n";
	else if (hit_points == 0)
		std::cout << "ClapTrap " << name << " is already broken\n";
	else if (hit_points == full_hp)
		std::cout << "ClapTrap " << name << " is already full hp max\n";
	else if (energy_points > 0)
	{
		energy_points--;
		if (hit_points + amount >= full_hp)
		{
			hit_points = full_hp;
			std::cout << "ClapTrap " << name << " has been completely fixed\n";
		}
		else
		{
			hit_points += amount;
			std::cout << "ClapTrap " << name << " fixed itself by " << amount << "\n";
		}
	}
	else
		std::cout << "ClapTrap " << name << " lacks energy\n";
}

std::string ClapTrap::getName() const
{
	return (name);
}

unsigned int ClapTrap::getDamage() const
{
	return (attack_damage);
}

void ClapTrap::printInfo() const
{
	std::cout << "name : " << name << std::endl;
	std::cout << "hp : " << hit_points << std::endl;
	std::cout << "ep : " << energy_points << std::endl;
	std::cout << "ad : " << attack_damage << std::endl;
}
