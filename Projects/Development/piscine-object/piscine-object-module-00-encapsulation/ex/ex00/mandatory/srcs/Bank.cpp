/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:21:37 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 09:02:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bank.hpp"

void Bank::errorMSG(std::string error) const { std::cerr << "Error: " << error << "." << std::endl; }

Bank::Bank(void) : _liquidity(0) {}

Bank::Bank(double liquidity) : _liquidity(liquidity) {}

Bank::Bank(const Bank &copy) : _liquidity(copy._liquidity) {}

Bank &Bank::operator=(const Bank &other)
{
	if (this != &other)
		this->_liquidity = other.getLiquidity();
	return *this;
}

Bank::~Bank() {}

double Bank::getLiquidity(void) const { return this->_liquidity; }

void Bank::increaseLiquidity(double amount) { this->_liquidity += amount; }

void Bank::decreaseLiquidity(double amount) { this->_liquidity -= amount; }

std::map<int, Account *> Bank::getClientAccounts(void) const { return this->_clientAccounts; }

bool Bank::accountExists(Account *account) const
{
	if (account == NULL)
		return false;
	std::map<int, Account *>::const_iterator it = this->_clientAccounts.begin();
	for (; it != this->_clientAccounts.end(); it++)
		if (it->second == account)
			return true;
	return false;
}

void Bank::addAccount(Account *account)
{
	if (account == NULL)
		return this->errorMSG(NULL_POINTER_ERROR);
	if (account->getId() < 0)
		return this->errorMSG(INVALID_ID_ERROR);
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account != this->_clientAccounts.end() || this->accountExists(account))
		return this->errorMSG(ACCOUNT_ALREADY_EXISTS_ERROR);
	this->_clientAccounts[account->getId()] = account;
}

void Bank::removeAccount(Account *account)
{
	if (account == NULL)
		return this->errorMSG(NULL_POINTER_ERROR);
	if (account->getId() < 0)
		return this->errorMSG(INVALID_ID_ERROR);
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account == this->_clientAccounts.end() || !this->accountExists(account))
		return this->errorMSG(ACCOUNT_NOT_FOUND_ERROR);
	this->_clientAccounts.erase(find_account);
}

void Bank::increaseAccountValue(Account *account, double amount)
{
	if (account == NULL)
		return this->errorMSG(NULL_POINTER_ERROR);
	if (account->getId() < 0)
		return this->errorMSG(INVALID_ID_ERROR);
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account == this->_clientAccounts.end() || !this->accountExists(account))
		return this->errorMSG(ACCOUNT_NOT_FOUND_ERROR);
	this->_clientAccounts[account->getId()]->_value += amount * 0.95;
	this->increaseLiquidity(amount * 0.05);
}

void Bank::giveLoanToAccount(Account *account, double amount)
{
	if (account == NULL)
		return this->errorMSG(NULL_POINTER_ERROR);
	if (account->getId() < 0)
		return this->errorMSG(INVALID_ID_ERROR);
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account == this->_clientAccounts.end() || !this->accountExists(account))
		return this->errorMSG(ACCOUNT_NOT_FOUND_ERROR);
	if (this->_liquidity < amount)
		return this->errorMSG(NOT_ENOUGH_LIQUIDITY_ERROR);
	this->_clientAccounts[account->getId()]->_value += amount;
	this->decreaseLiquidity(amount);
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
	const std::map<int, Account *> accounts = p_bank.getClientAccounts();
	std::map<int, Account *>::const_iterator it = accounts.begin();
	for (; it != accounts.end(); it++)
		p_os << *it->second << std::endl;
	return (p_os);
}
