#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::string("Please input one argument");
		RPN rpn;
		std::string expression(argv[1]);
		int length = expression.size();
		for (int i = 0; i < length; i++)
		{
			if ((i & 1) == 0) rpn.inputChar(expression[i]);
			else if (expression[i] != ' ') throw std::string("Error");
		}
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::string& e)
	{
		std::cout << e << '\n';
		return (1);
	}
	return (0);
}