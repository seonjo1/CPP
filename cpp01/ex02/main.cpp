#include <iostream>
#include <string>

int main()
{
	std::string sval("HI THIS IS BRAIN");
	std::string* stringPTR = &sval;
	std::string& stringREF = sval;

	std::cout << "Address of string variable : " << &sval << std::endl;
	std::cout << "Address of held by stringPTR : " << &stringPTR << std::endl;
	std::cout << "Address of held by stringREF : " << &stringREF << std::endl << std::endl;

	std::cout << "Value of string variable : " << sval << std::endl;
	std::cout << "value pointed to by stringPTR : " << stringPTR << std::endl;
	std::cout << "value pointed to by stringREF : " << stringREF << std::endl;

	return (0);
}