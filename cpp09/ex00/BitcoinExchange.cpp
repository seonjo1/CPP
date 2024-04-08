#ifndef BITCOINEXCHANGE_CPP
# define BITCOINEXCHANGE_CPP

# include <map>
# include <string>

class BitcoinExchange
{
private:
	std::map<int, int> map;
public:
	BitcoinExchange();
	BitcoinExchange(std::string& data);
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	float findExchangeRate(std::string date, std::string value);
};

#endif

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(std::string& data)
{
	// data map에 저장
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

float BitcoinExchange::findExchangeRate(std::string date, std::string value)
{

}

