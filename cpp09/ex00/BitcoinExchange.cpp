#ifndef BITCOINEXCHANGE_CPP
# define BITCOINEXCHANGE_CPP

# include <map>

class BitcoinExchange
{
private:
	std::map<int, int> map;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();
	BitcoinExchange&	operator=(const BitcoinExchange& copy);
};

#endif

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
	: map(copy.map) {};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this != &copy)
		map = copy.map;
	return (*this);
}
