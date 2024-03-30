#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "Too few arguments\n";
	else if (argc != 2)
		std::cout << "Too many arguments\n";
	else
	{
		ScalarConverter::convert(argv[1]);
		return (0);
	}
	return (1);
}