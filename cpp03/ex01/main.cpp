#include "ScavTrap.hpp"

int main()
{
	ScavTrap A(std::string("A"));
	ScavTrap B(std::string("B"));
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(A.getDamage());
	A.printInfo();
	B.printInfo();
	A.guardGate();
	B.guardGate();

	return (0);
}