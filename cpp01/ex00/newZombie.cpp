#include "Zombie.hpp"

void	new_zombie_test()
{
	Zombie zombie("caller");

	std::string name1("one_hp");
	Zombie *zom1 = zombie.newZombie(name1);
	zom1->announce();

	std::string name2("two_hp");
	Zombie *zom2 = zombie.newZombie(name2);
	zom2->announce();

	std::string name3("three_hp");
	Zombie *zom3 = zombie.newZombie(name3);
	zom3->announce();
	
	std::cout << "call delete\n";
	delete zom1;
	std::cout << "call delete\n";
	delete zom2;
	std::cout << "call delete\n";
	delete zom3;
}