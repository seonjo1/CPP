#include "FragTrap.hpp"

int main()
{
	FragTrap A(std::string("A"));
	FragTrap B(std::string("B"));
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(A.getDamage());
	A.printInfo();
	B.printInfo();
	A.highFivesGuy();
	B.highFivesGuy();

	return (0);
}