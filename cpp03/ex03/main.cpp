#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap A(std::string("A"));
	DiamondTrap B(std::string("B"));
	std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(A.getDamage());
	A.printInfo();
	B.printInfo();
	A.highFivesGuy();
	B.guardGate();
	A.whoAmI();
	B.whoAmI();

	return (0);
}