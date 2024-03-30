#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cmath>
# include <limits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& obj);

public:
	static void convert(std::string str);
};

#endif
