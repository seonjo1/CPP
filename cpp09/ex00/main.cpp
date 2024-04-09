#include "BitcoinExchange.hpp"

void argumentCheck(int argc)
{
	if (argc != 2)
	{
		std::cerr << "Error: please input one argument\n";
		std::exit(1);
	}
}

void openFile(std::ifstream& input, char *file)
{
	input.open(file);
	if (!input.is_open())
	{
		std::cerr << "Error: fail to open input file\n";
		std::exit(1);
	}
}

void lineCheck(std::string line)
{
	if (line.size() < 14) throw (std::string("Error: bad input => ") + line);
	if (line[10] != ' ') throw (std::string("Error: bad input => ") + line);
	if (line[11] != '|') throw (std::string("Error: bad input => ") + line);
	if (line[12] != ' ') throw (std::string("Error: bad input => ") + line);
}

float getValue(std::string line)
{
	int i = 0;
	int dotNum = 0;
	int length = static_cast<int>(line.size());

	if (line[i] == '+') i++;
	for (; i < length; i++)
	{
		if (line[i] == '.')
			dotNum++;
		else if (!std::isdigit(line[i]))
			throw std::string("Error: invalid value");
	}
	if (dotNum > 1)
		throw std::string("Error: invalid value");

	float value;
	std::stringstream ss(line.c_str());
	ss >> value;
	if (ss.fail()) throw std::string("Error: invalid value");
	if (value < 0.0f) throw std::string("Error: not a positive number");
	if (value > 1000.0f) throw std::string("Error: too large a number");
	return (value);
}

void printResult(std::string line, float value, float rate)
{
	std::cout << line.substr(0, 10) << " => " << value << " = " << value * rate << std::endl;
}

int main(int argc, char **argv)
{
	argumentCheck(argc);

	BitcoinExchange BE("data.csv");

	std::ifstream input;
	openFile(input, argv[1]);

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		try
		{
			lineCheck(line);
			printResult(line, getValue(line.substr(13)), BE.getExchangeRate(line.substr(0, 10)));
		}
		catch(const std::string& e)
		{
			std::cerr << e << '\n';
		}
	}

	return (0);
}