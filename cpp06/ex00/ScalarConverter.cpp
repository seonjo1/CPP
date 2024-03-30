#include "ScalarConverter.hpp"

void printOverflow(const char *str)
{
	std::cout << str << "overflow" <<std::endl;
}

void printChar(char c)
{
	if (isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void printInt(int n)
{
	std::cout << "int: " << n << std::endl;
}

void printFloat(float fp)
{
	if (fmod(fp, 1) == 0)
		std::cout << "float: " << fp << ".0f" << std::endl;
	else
		std::cout << "float: " << fp << "f" << std::endl;
}

void printDouble(double fp)
{
	if (fmod(fp, 1) == 0)
		std::cout << "double: " << fp << ".0" << std::endl;
	else
		std::cout << "double: " << fp << std::endl;
}

bool isNum(std::string& str)
{
	int i = 0;
	int len = str.length();

	if (str[i] == '+' || str[i] == '-')
	{
		if (len == 1)
			return (false);
		i++;
		if (len != 2 && str[i] == '0')
			return (false);
	}
	else if (len != 1 && str[i] == '0')
		return (false);
	
	for (; i < len; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool isChar(std::string& str)
{
	if (str.length() != 1)
		return (false);
	else
		return (true);
}

bool isInt(std::string& str)
{
	if (!isNum(str))
		return (false);
	return (true);
}

bool isFloat(std::string& str)
{
	bool containDigit = false;
	int i = 0;
	int len = str.length();
	while (i < len && str[i] == '0')
	{
		i++;
		containDigit = true;
	}

	int dotNum = 0;
	for (; i < len - 1; i++)
	{
		if (isdigit(str[i]))
			containDigit = true;
		else if (str[i] == '.')
			dotNum++;
	}
	if (dotNum == 1 && containDigit && str[len - 1] == 'f')
		return (true);
	return (false);
}

// bool isDouble(std::string& str)
// {
// 	bool containDigit = false;
// 	int i = 0;
// 	int len = str.length();
// 	while (i < len && str[i] == '0')
// 	{
// 		i++;
// 		containDigit = true;
// 	}

// 	int dotNum = 0;
// 	for (; i < len - 1; i++)
// 	{
// 		if (isdigit(str[i]))
// 			containDigit = true;
// 		else if (str[i] == '.')
// 			dotNum++;
// 	}
// 	if (dotNum == 1 && containDigit && str[len - 1] == 'f')
// 		return (true);
// 	return (false);
// }

void castChar(std::string& str)
{	
	char c = str[0];
	printChar(c);
	printInt(static_cast<int>(c));
	printFloat(static_cast<float>(c));
	printDouble(static_cast<double>(c));
}

void castInt(std::string& str)
{
	std::stringstream stream(str.c_str());
	
	int n;
	stream >> n;
	if (stream.fail())
	{
		std::cout << "int overflow\n";
	}
	else
	{
		if (n < CHAR_MIN || n > CHAR_MAX)
			printOverflow("char: ");
		else
			printChar(static_cast<char>(n));

		printInt(n);
		
		printFloat(static_cast<float>(n));
		
		printDouble(static_cast<double>(n));
	}
}

void castFloat(std::string& str)
{
	str = str.substr(0, str.length() - 1);
	std::stringstream stream(str.c_str());

	float fp;
	stream >> fp;
	if (stream.fail())
	{
		std::cout << "float overflow\n";
	}
	else
	{
		if (fp < CHAR_MIN || fp > CHAR_MAX)
			printOverflow("char: ");
		else
			printChar(static_cast<char>(fp));

		if (fp < INT_MIN || fp > INT_MAX)
			printOverflow("int: ");
		else
			printInt(static_cast<int>(fp));

		printFloat(fp);

		printDouble(static_cast<double>(fp));
	}
}

void ScalarConverter::convert(std::string str)
{
	if (str.length() == 0)
		std::cout << "Argument is invalid\n";
	else if (isChar(str))
		castChar(str);
	else if (isInt(str))
		castInt(str);
	else if (isFloat(str))
		castFloat(str);
	else
		std::cout << "invalid argument\n";
	// else if (isDouble(str))
	// {

	// }
	// else if (isNotSpecialValue(str))
	// 	std::cout << "Argument is invalid\n";
}
