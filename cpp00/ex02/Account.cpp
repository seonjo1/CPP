#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = 0;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << checkAmount() + deposit << ";";
	std::cout << "nb_deposits:" << _nbDeposits + 1 << "\n";
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	if (_amount >= withdrawal)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << checkAmount() - withdrawal << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals + 1 << "\n";
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
}

int Account::checkAmount() const
{
	return (_amount);
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void Account::_displayTimestamp()
{
	std::time_t now = std::time(0);
	std::tm* tm = std::localtime(&now);
	std::cout << "[" << tm->tm_year + 1900;
	if (tm->tm_mon < 9)
		std::cout << "0";
	std::cout << tm->tm_mon + 1;
	if (tm->tm_mday < 10)
		std::cout << "0";
	std::cout << tm->tm_mday << "_";
	if (tm->tm_hour < 10)
		std::cout << "0";
	std::cout << tm->tm_hour;
	if (tm->tm_min < 10)
		std::cout << "0";
	std::cout << tm->tm_min;
	if (tm->tm_sec < 10)
		std::cout << "0";
	std::cout << tm->tm_sec << "] ";
}
