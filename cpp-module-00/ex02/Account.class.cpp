#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.class.hpp"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
				";amount:" << _amount << ";created" << std::endl;
}

Account::Account()
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
				";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
				";amount:" << _amount << ";closed" << std::endl;
}

int		Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() <<
				";total:" << getTotalAmount() <<
				";deposits:" << getNbDeposits() <<
				";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
				";p_amount:" << _amount - deposit <<
				";deposit:" << deposit <<
				";amount:" << _amount <<
				";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
				";p_amount:" << _amount <<
				";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount <<
		";nb_withdrawals:" << _nbDeposits << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount > 0);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex <<
				";amount:" << _amount <<
				";deposits:" << _nbDeposits <<
				";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t		rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::cout << "[" << std::setfill('0') <<
		timeinfo->tm_year + 1900 << std::setw(2) <<
		timeinfo->tm_mon + 1 << std::setw(2) <<
		timeinfo->tm_mday << "_" << std::setw(2) <<
		timeinfo->tm_hour << std::setw(2) <<
		timeinfo->tm_min << std::setw(2) <<
		timeinfo->tm_sec << std::setfill(' ') << "] ";
}
