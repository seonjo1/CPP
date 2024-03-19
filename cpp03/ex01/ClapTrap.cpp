#include "ClapTrap.hpp"

const unsigned int ClapTrap::full_hp = 10;
const unsigned int ClapTrap::full_ep = 10;
const unsigned int ClapTrap::full_ad = 0;

ClapTrap::ClapTrap()
	: hit_points(full_hp), energy_points(full_ep), attack_damage(full_ad)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(std::string name)
	: name(name), hit_points(full_hp), energy_points(full_ep), 
		attack_damage(full_ad)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: name(obj.name), hit_points(obj.hit_points), energy_points(obj.energy_points), 
		attack_damage(obj.attack_damage)
{
	std::cout << "ClapTrap constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	name = obj.name;
	hit_points = obj.hit_points;
	energy_points = obj.energy_points;
	attack_damage = obj.attack_damage;
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

std::string ClapTrap::get_name() const
{
	return (name);
}

unsigned int ClapTrap::get_damage() const
{
	return (attack_damage);
}