#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
protected:
	bool guardGatemode;

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& obj);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap& obj);
	void attack(const std::string& target);
	void guardGate();
};

#endif