#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "DEBUG LEVEL\n";
	harl.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "INFO LEVEL\n";
	harl.complain("INFO");
	std::cout << std::endl;

	std::cout << "WARNING LEVEL\n";
	harl.complain("WARNING");
	std::cout << std::endl;

	std::cout << "ERROR LEVEL\n";
	harl.complain("ERROR");
	std::cout << std::endl;

	return (0);
}