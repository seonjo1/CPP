#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "DEBUG LEVEL\n";
	harl.complain("DEBUG");
	std::cout << "\n\n";

	std::cout << "INFO LEVEL\n";
	harl.complain("INFO");
	std::cout << "\n\n";

	std::cout << "WARNING LEVEL\n";
	harl.complain("WARNING");
	std::cout << "\n\n";

	std::cout << "ERROR LEVEL\n";
	harl.complain("ERROR");
	std::cout << "\n\n";

	return (0);
}