#include "Zombie.hpp"

void zombieHorde_test()
{
	Zombie zom("caller");

	int	N = 5;
	std::cout << "create a group of " << N << " seonjo zombies\n";
	Zombie* zombies = zom.zombieHorde(N, std::string("seonjo"));
	for (int i = 0; i < N; i++)
	{
		std::cout << i + 1 << "th zombie announce himself\n";
		zombies[i].announce();
	}
	delete []zombies;
}
