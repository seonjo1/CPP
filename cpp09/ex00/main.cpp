#include "BitcoinExchange.hpp"

void argumentCheck(int argc)
{
	if (argc != 2)
	{
		std::cerr << "Error: please input one argument\n";
		std::exit(1);
	}
}

std::ifstream& openFile(char *file)
{
	std::ifstream input;
	input.open(argv[1]);
	if (input.is_open())
		return (input);
	std::cerr << "Error: fail to open input file\n";
	std::exit(1);
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
	float value;
	std::stringstream ss(line.c_str());
	ss >> value;
	if (ss.fail()) throw std::string("Error: invalid value");
	if (value < 0.0f) throw std::string("Error: not a positive number");
	if (value > 1000.0f) throw std::string("Error: too large a number");
}

void printResult(std::string line, float value, float rate)
{
	std::cout << line.substr(0, 10) << " => " << value << " = " << value * rate << std::endl;
}

int main(int argc, char **argv)
{
	argumentCheck(argc);

	BitcoinExchange BE("data.scv");
	std::ifstream input = openFile(argv[1]);

	std::string line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		try
		{
			LineCheck(line);
			printResult(line, getValue(substr(13)), BE.getExchangeRate(line.substr(0, 10)));
		}
		catch(const std::string& e)
		{
			std::cerr << e << '\n';
		}
	}

	return (0);
}