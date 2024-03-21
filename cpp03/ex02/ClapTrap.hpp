#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	std::string	name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

	unsigned int full_hp;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(unsigned int hp, unsigned int ep, unsigned int ad);
	ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
	ClapTrap(const ClapTrap& obj);
	virtual ~ClapTrap();
	ClapTrap& operator=(const ClapTrap& obj);

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	unsigned int getDamage() const;
	void printInfo() const;
};

#endif

