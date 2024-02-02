/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:16:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/02 22:17:58 by dcaetano         ###   ########.fr       */
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
	std::map<std::string, ASpell*>::iterator it = _spells.begin();
	while (it != _spells.end())
	{
		delete it->second;
		++it;
	}
	_spells.clear();
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

void Warlock::learnSpell(ASpell* spell)
{
	if (!spell)
		return ;
	if (_spells.find(spell->getName()) == _spells.end())
		_spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string spell_name)
{
	std::map<std::string, ASpell*>::iterator it = _spells.find(spell_name);
	if (it != _spells.end())
	{
		delete it->second;
		_spells.erase(it);
	}
}

void Warlock::launchSpell(std::string spell_name, const ATarget& target)
{
	if (_spells.find(spell_name) != _spells.end())
		_spells[spell_name]->launch(target);
}
