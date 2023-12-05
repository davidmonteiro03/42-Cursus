/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:35:28 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/05 13:52:26 by dcaetano         ###   ########.fr       */
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
	std::cout << " amount:" << this->_amount;
	std::cout << ";created" << std::endl;
	Account::_nbAccounts++;
}

Account::~Account(void)
{
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
}

void	Account::displayStatus(void) const
{
}

void	Account::makeDeposit(int deposit)
{
	this->_amount = deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	(void)withdrawal;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}
