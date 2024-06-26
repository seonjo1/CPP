#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "please input one argument\n";
		return (1);
	}

	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string level(argv[1]);

	int num = 5;
	for (int i = 0; i < 4; i++)
	{
		if (arr[i].compare(level) == 0)
		{
			num = i;
			break;
		}
	}

	Harl harl;

	switch (num)
	{
		case 0:
			harl.complain(arr[0]);
			// FALLTHROUGH
		case 1:
			harl.complain(arr[1]);
			// FALLTHROUGH
		case 2:
			harl.complain(arr[2]);
			// FALLTHROUGH
		case 3:
			harl.complain(arr[3]);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return (0);
}