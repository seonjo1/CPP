#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str("");
			for (int j = 0; argv[i][j] != '\0'; j++)
				str += toupper(argv[i][j]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}