#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>
# include <string>
# include <cstdlib>
# include <sstream>
# include <iostream>

class BitcoinExchange
{
private:
	std::map<int, float> map;
	
	void inputData(std::string line);
	int convertingToInt(std::string str);
	float convertingToFloat(std::string str);

public:
	BitcoinExchange();
	BitcoinExchange(char *dataFile);
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	float getExchangeRate(std::string date, std::string value);
};

#endif

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

int BitcoinExchange::convertingToInt(std::string str)
{

}

float BitcoinExchange::convertingToFloat(std::string str)
{

}

void BitcoinExchange::inputData(std::string line)
{
	int key;
	float value;

	key = convetingToInt(line.substr(0, 4));
	key = (key << 4) | convertingToInt(line.substr(5, 2));
	key = (key << 5) | convertingToInt(line.substr(8, 2));
	value = convertingToFloat(line.substr(12));
	map.insert(std::make_pair(key, value));
}

BitcoinExchange::BitcoinExchange(char *dataFile)
{
	std::ifstream data;
	data.open(dataFile);
	if (data.is_open())
	{
		std::string line;
		std::getline(input, line);
		while(getline(input, line))
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

float BitcoinExchange::getExchangeRate(std::string date)
{
	//date int로 변환

	//date 유효성 검사 

	// map 탐색

	// 성공시와 실패시 따로 return
}

