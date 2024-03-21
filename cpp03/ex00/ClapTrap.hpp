#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
private:
	std::string	name;
	unsigned int hit_points;
	unsigned int energy_points;
	unsigned int attack_damage;

	unsigned int full_hp;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& obj);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName() const;
	unsigned int getDamage() const;
	void printInfo() const;
};

#endif

