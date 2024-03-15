#include "Zombie.hpp"

Zombie::Zombie() {};

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

void Zombie::set_name(std:: string &name)
{
	this->name = name;
}

Zombie* Zombie::zombieHorde(int N, std::string name)
{
	try
	{		
		Zombie *zombies = new Zombie[N];
		for (int i = 0; i < N; i++)
			zombies[i].set_name(name);
		return (zombies);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		std::exit(EXIT_FAILURE);
	}
}
