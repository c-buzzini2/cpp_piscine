/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbuzzini <cbuzzini@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:46:53 by cbuzzini          #+#    #+#             */
/*   Updated: 2026/01/10 16:37:21 by cbuzzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << "\033[94m" << this->_accountIndex << "\033[0m"
				<< ";amount:" << "\033[94m" << this->_amount << "\033[0m"
				<< ";created"
				<< std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << "\033[94m" << this->_accountIndex << "\033[0m"
				<< ";amount:" << "\033[94m" << this->_amount << "\033[0m"
				<< ";closed"
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm* time = std::localtime(&now);
	char buffer[20];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", time);
	std::cout << buffer;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << "\033[94m" << Account::getNbAccounts() << "\033[0m"
				<< ";total:" << "\033[94m" << Account::getTotalAmount() << "\033[0m"
				<< ";deposits:" << "\033[94m" << Account::getNbDeposits() << "\033[0m"
				<< ";withdrawals:" << "\033[94m" << Account::getNbWithdrawals() << "\033[0m"
				<< std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << "\033[94m" << this->_accountIndex << "\033[0m"
				<< ";amount:" << "\033[94m" << this->checkAmount() << "\033[0m"
				<< ";deposits:" << "\033[94m" << this->_nbDeposits << "\033[0m"
				<< ";withdrawals:" << "\033[94m" << this->_nbWithdrawals << "\033[0m"
				<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << "\033[94m" << this->_accountIndex << "\033[0m"
				<< ";p_amount:" << "\033[94m" << this->checkAmount() << "\033[0m";
	this->_amount += deposit;
	_totalAmount += deposit;
	
	this->_nbDeposits++;
	_totalNbDeposits++;
	
	std::cout << ";deposit:" << "\033[94m" << deposit << "\033[0m"
				<< ";amount:" << "\033[94m" << this->checkAmount() << "\033[0m"
				<< ";nb_deposits:" << "\033[94m" << this->_nbDeposits << "\033[0m"
				<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << "\033[94m" << this->_accountIndex << "\033[0m"
				<< ";p_amount:" << "\033[94m" << this->checkAmount() << "\033[0m";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused"
				<< std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	
	std::cout << ";withdrawal:" << "\033[94m" << withdrawal << "\033[0m"
				<< ";amount:" << "\033[94m" << this->checkAmount() << "\033[0m"
				<< ";nb_withdrawals:" << "\033[94m" << this->_nbWithdrawals << "\033[0m"
				<< std::endl;
	return (true);
}
