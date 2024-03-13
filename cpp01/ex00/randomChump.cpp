#include "Zombie.hpp"

void	random_chump_test()
{
	Zombie zombie("caller");

	std::string name1("one_st");
	zombie.randomChump(name1);

	std::string name2("two_st");
	zombie.randomChump(name2);

	std::string name3("three_st");
	zombie.randomChump(name3);
}
