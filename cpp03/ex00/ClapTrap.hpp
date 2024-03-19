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

	static const unsigned int full_hp;
	static const unsigned int full_ep;
	static const unsigned int full_ad;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& obj);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& obj);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string get_name() const;
	unsigned int get_damage() const;
};

#endif

