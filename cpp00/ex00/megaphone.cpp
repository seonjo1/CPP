#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	char	c;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str("");
			for (int j = 0; argv[i][j] != '\0'; j++)
			{
				c = argv[i][j];
				if (c >= 'a' && c <= 'z')
					c = c - ('a' - 'A');
				str += c;
			}
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}