/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:22:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 08:16:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

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

std::ostream &operator<<(std::ostream &, const Account &);

#endif // !ACCOUNT_HPP
