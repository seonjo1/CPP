#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const char *dataFile)
{
	std::ifstream data;
	data.open(dataFile);
	if (data.is_open())
	{
		std::string line;
		std::getline(data, line);
		while(getline(data, line))
		{
			if (line.size() > 11)
				inputData(line);
		}
	}
	else
	{
		std::cerr << "Error: fail to open data file\n";
		std::exit(1);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
	: map(copy.map) {};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		map = copy.map;
	return (*this);
}

void BitcoinExchange::checkDate(int* dayList, int year, int month, int day)
{
	if (year < 1) throw std::string("Error: invalid date");
	if (month < 1 || month > 12) throw std::string("Error: invalid date");
	if (day < 1 || day > dayList[month]) throw std::string("Error: invalid date");
}

float BitcoinExchange::getExchangeRate(std::string date)
{
	static int leapYearDay[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	static int defaultDay[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date[4] != '-' || date[7] != '-') throw std::string("Error: invalid date");

	int year = convertingToInt(date.substr(0, 4));
	int month = convertingToInt(date.substr(5, 2));
	int day = convertingToInt(date.substr(8, 2));

	// std::cout << "year : " << year << std::endl;
	// std::cout << "month : " << month << std::endl;
	// std::cout << "day : " << day << std::endl;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		checkDate(leapYearDay, year, month, day);
	else
		checkDate(defaultDay, year, month, day);

	int key = ((((year << 4) | month) << 5) | day);
	std::map<int, float>::iterator iter = map.lower_bound(key);
	if (iter == map.end()) return ((--map.end())->second);
	else if (iter == map.begin()) return (iter->second);
	else if (iter->first == key) return (iter->second);
	else return ((--iter)->second);
}

int BitcoinExchange::convertingToInt(std::string str)
{
	int length = static_cast<int>(str.size());
	for (int i = 0; i < length; i++)
	{
		if (!std::isdigit(str[i]))
			throw std::string("Error: invalid date");
	}
	std::stringstream ss(str.c_str());
	int val;
	ss >> val;
	if (ss.fail()) throw std::string("Error: invalid date");
	return (val);
}

float BitcoinExchange::convertingToFloat(std::string str)
{
	std::stringstream ss(str.c_str());
	float val;
	ss >> val;
	if (ss.fail()) throw std::string("Error: invalid rate");
	return (val);
}

void BitcoinExchange::inputData(std::string line)
{
	int key;
	float value;

	try
	{
		key = convertingToInt(line.substr(0, 4));
		key = (key << 4) | convertingToInt(line.substr(5, 2));
		key = (key << 5) | convertingToInt(line.substr(8, 2));
		value = convertingToFloat(line.substr(11));
		map.insert(std::make_pair(key, value));
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
}
