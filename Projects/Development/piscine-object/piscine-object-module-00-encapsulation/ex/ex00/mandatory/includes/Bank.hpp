/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:18:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 09:04:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>
#include "Account.hpp"

# define NULL_POINTER_ERROR "Null Pointer"
# define INVALID_ID_ERROR "Invalid ID"
# define ACCOUNT_ALREADY_EXISTS_ERROR "Account Already Exists"
# define ACCOUNT_NOT_FOUND_ERROR "Account Not Found"
# define NOT_ENOUGH_LIQUIDITY_ERROR "Not Enough Liquidity"

class Bank
{
public:
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

private:
	double _liquidity;
	std::map<int, Account *> _clientAccounts;
	bool accountExists(Account *) const;
	void errorMSG(std::string) const;
};

std::ostream &operator<<(std::ostream &, const Bank &);

#endif // !BANK_HPP
