#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <map>
# include <string>
# include <cstdlib>
# include <sstream>
# include <iostream>
# include <cctype>

class BitcoinExchange
{
private:
	std::map<int, float> map;

	void inputData(std::string line);
	int convertingToInt(std::string str);
	float convertingToFloat(std::string str);
	void checkDate(int* dayList, int year, int month, int day);

public:
	BitcoinExchange();
	BitcoinExchange(const char *dataFile);
	BitcoinExchange(const BitcoinExchange& copy);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& copy);
	float getExchangeRate(std::string date);

};

#endif