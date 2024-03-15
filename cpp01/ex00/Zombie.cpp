#include "Zombie.hpp"

Zombie::Zombie(std::string name)
	: name(name) {};

Zombie::~Zombie()
{
	std::cout << name << " Zombie is gone\n";
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie*	Zombie::newZombie(std::string name)
{
	try
	{
		Zombie *zombie = new Zombie(name);
		return (zombie);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
	
}

void	Zombie::randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}