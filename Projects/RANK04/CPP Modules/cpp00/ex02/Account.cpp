/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:35:28 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/05 15:53:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;

int	Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::getNbAccounts();
	this->_amount = initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";created";
	std::cout << std::endl;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed";
	std::cout << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void)
{
	time_t	now = time(NULL);
	char	buffer[256];

	strftime(buffer, 256, "[%Y%m%d_%H%M%S]", std::localtime(&now));
	std::cout << buffer;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;
	this->_nbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";p_amount:" << this->_amount;
	std::cout << ";withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	std::cout << ";amount:" << this->_amount;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << ";nb_withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}
