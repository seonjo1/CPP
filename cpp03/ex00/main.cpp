#include "ClapTrap.hpp"

int main()
{
	ClapTrap A(std::string("A"));
	ClapTrap B(std::string("B"));
	ClapTrap C(std::string("C"));
	std::cout << std::endl;

	for (int i = 0; i < 3; i++)
	{
		A.attack(B.getName());
		B.takeDamage(A.getDamage());
	}
	std::cout << std::endl;

	A.takeDamage(4000000000);
	C.beRepaired(4000000000);
	C.takeDamage(3999999999);
	std::cout << std::endl;

	A.takeDamage(3);
	A.beRepaired(2);
	A.beRepaired(2);
	A.beRepaired(2);
	A.takeDamage(3);
	A.beRepaired(2);
	A.takeDamage(3);
	A.beRepaired(2);
	A.takeDamage(3);
	A.beRepaired(2);
	A.takeDamage(3);
	A.beRepaired(2);
	A.printInfo();
	A.takeDamage(3);
	A.beRepaired(2);
	A.printInfo();
	A.takeDamage(3);
	A.beRepaired(2);
	A.printInfo();
	std::cout << std::endl;

	B.takeDamage(4);
	B.printInfo();
	B.takeDamage(4);
	B.printInfo();
	B.takeDamage(4);
	B.printInfo();
	B.takeDamage(4);
	B.beRepaired(2);
	B.attack(A.getName());	
}