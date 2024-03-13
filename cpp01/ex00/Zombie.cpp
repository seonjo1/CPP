#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: _name(name) {};

Zombie::~Zombie()
{
	std::cout << _name << " Zombie is gone\n";
}

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie*	Zombie::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	return (zombie);
}

void	Zombie::randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}