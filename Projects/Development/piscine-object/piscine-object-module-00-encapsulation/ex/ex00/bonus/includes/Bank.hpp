/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:18:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 08:52:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>
#include <stdexcept>

class Bank
{
public:
	class Account
	{
	public:
		Account(void);
		Account(int, double);
		Account(const Account &);
		Account &operator=(const Account &);
		~Account();
		int getId(void) const;
		double getValue(void) const;

	private:
		const int _id;
		double _value;
		friend class Bank;
	};
	Bank(void);
	Bank(double);
	Bank(const Bank &);
	Bank &operator=(const Bank &);
	~Bank();
	double getLiquidity(void) const;
	std::map<int, Account *> getClientAccounts(void) const;
	void increaseLiquidity(double);
	void decreaseLiquidity(double);
	void addAccount(Account *);
	void removeAccount(Account *);
	void increaseAccountValue(Account *, double);
	void giveLoanToAccount(Account *, double);
	Account &operator[](int);
	class NullPointerException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class InvalidIDException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class AccountNotFoundException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class AccountAlreadyExistsException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class NotEnoughLiquidityException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

private:
	double _liquidity;
	std::map<int, Account *> _clientAccounts;
	bool accountExists(Account *) const;
};

std::ostream &operator<<(std::ostream &, const Bank &);
std::ostream &operator<<(std::ostream &, const Bank::Account &);

#endif // !BANK_HPP
