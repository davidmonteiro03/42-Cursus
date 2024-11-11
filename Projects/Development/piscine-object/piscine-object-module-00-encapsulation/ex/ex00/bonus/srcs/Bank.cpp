/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:21:37 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 09:00:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bank.hpp"

Bank::Account::Account(void) : _id(-1), _value(0) {}

Bank::Account::Account(int id, double value) : _id(id), _value(value) {}

Bank::Account::Account(const Account &copy) : _id(copy._id), _value(copy._value) {}

Bank::Account &Bank::Account::operator=(const Account &other)
{
	if (this != &other)
		this->_value = other.getValue();
	return *this;
}

Bank::Account::~Account() {}

int Bank::Account::getId(void) const { return this->_id; }

double Bank::Account::getValue(void) const { return this->_value; }

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

std::map<int, Bank::Account *> Bank::getClientAccounts(void) const { return this->_clientAccounts; }

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
		throw NullPointerException();
	if (account->getId() < 0)
		throw InvalidIDException();
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account != this->_clientAccounts.end() || this->accountExists(account))
		throw AccountAlreadyExistsException();
	this->_clientAccounts[account->getId()] = account;
}

void Bank::removeAccount(Account *account)
{
	if (account == NULL)
		throw NullPointerException();
	if (account->getId() < 0)
		throw InvalidIDException();
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account == this->_clientAccounts.end() || !this->accountExists(account))
		throw AccountNotFoundException();
	this->_clientAccounts.erase(find_account);
}

void Bank::increaseAccountValue(Account *account, double amount)
{
	if (account == NULL)
		throw NullPointerException();
	if (account->getId() < 0)
		throw InvalidIDException();
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account == this->_clientAccounts.end() || !this->accountExists(account))
		throw AccountNotFoundException();
	this->_clientAccounts[account->getId()]->_value += amount * 0.95;
	this->increaseLiquidity(amount * 0.05);
}

void Bank::giveLoanToAccount(Account *account, double amount)
{
	if (account == NULL)
		throw NullPointerException();
	if (account->getId() < 0)
		throw InvalidIDException();
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(account->getId());
	if (find_account == this->_clientAccounts.end() || !this->accountExists(account))
		throw AccountNotFoundException();
	if (this->_liquidity < amount)
		throw NotEnoughLiquidityException();
	this->_clientAccounts[account->getId()]->_value += amount;
	this->decreaseLiquidity(amount);
}

Bank::Account &Bank::operator[](int id)
{
	if (id < 0)
		throw InvalidIDException();
	std::map<int, Account *>::iterator find_account;
	find_account = this->_clientAccounts.find(id);
	if (find_account == this->_clientAccounts.end())
		throw AccountNotFoundException();
	return *find_account->second;
}

const char *Bank::NullPointerException::what() const throw() { return "Null Pointer Exception"; }

const char *Bank::InvalidIDException::what() const throw() { return "Invalid ID Exception"; }

const char *Bank::AccountNotFoundException::what() const throw() { return "Account Not Found Exception"; }

const char *Bank::AccountAlreadyExistsException::what() const throw() { return "Account Already Exists Exception"; }

const char *Bank::NotEnoughLiquidityException::what() const throw() { return "Not Enough Liquidity Exception"; }

std::ostream &operator<<(std::ostream &p_os, const Bank::Account &p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return p_os;
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank.getLiquidity() << std::endl;
	const std::map<int, Bank::Account *> accounts = p_bank.getClientAccounts();
	std::map<int, Bank::Account *>::const_iterator it = accounts.begin();
	for (; it != accounts.end(); it++)
		p_os << *it->second << std::endl;
	return (p_os);
}
