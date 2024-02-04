/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:34:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/04 17:35:12 by dcaetano         ###   ########.fr       */
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

void Warlock::learnSpell(ASpell* spell) { _book.learnSpell(spell); }

void Warlock::forgetSpell(std::string spell_name) { _book.forgetSpell(spell_name); }

void Warlock::launchSpell(std::string spell_name, const ATarget& target)
{
	if (_book.createSpell(spell_name))
		_book.createSpell(spell_name)->launch(target);
}
