#include "Zombie.hpp"

Zombie::Zombie() {};

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

void Zombie::set_name(std:: string &name)
{
	_name = name;
}

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return (zombies);
}
