#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <new>
# include <cstdlib>

class Zombie
{
private:
	Zombie();
	std::string name;
	void set_name(std:: string &name);

public:
	Zombie(std::string name);
	~Zombie();
	void announce();
	Zombie* zombieHorde(int N, std::string name);
};

#endif