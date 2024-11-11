/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:22:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 08:56:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

Account::Account(void) : _id(-1), _value(0) {}

Account::Account(int id, double value) : _id(id), _value(value) {}

Account::Account(const Account &copy) : _id(copy._id), _value(copy._value) {}

Account &Account::operator=(const Account &other)
{
	if (this != &other)
		this->_value = other.getValue();
	return *this;
}

Account::~Account() {}

int Account::getId(void) const { return this->_id; }

double Account::getValue(void) const { return this->_value; }

std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
{
	p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
	return p_os;
}
