/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:12:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/02 22:13:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title) : \
	_name(name), _title(title)
{
	std::cout << _name;
	std::cout << ": This looks like another boring day.";
	std::cout << std::endl;
}

Warlock::~Warlock()
{
	std::cout << _name;
	std::cout << ": My job here is done!";
	std::cout << std::endl;
}

const std::string& Warlock::getName(void) const { return (_name); }

const std::string& Warlock::getTitle(void) const { return (_title); }

void Warlock::setTitle(const std::string& title) { _title = title; }

void Warlock::introduce() const
{
	std::cout << _name;
	std::cout << ": I am ";
	std::cout << _name;
	std::cout << ", ";
	std::cout << _title;
	std::cout << "!";
	std::cout << std::endl;
}
