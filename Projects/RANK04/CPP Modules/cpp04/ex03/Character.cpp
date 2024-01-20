/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 22:10:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/20 22:16:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
}

Character::~Character()
{
	std::vector<AMateria*>::iterator it = _inventory.begin();
	while (it != _inventory.end())
	{
		delete *it;
		++it;
	}
	_inventory.clear();
}

std::string const & Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	_inventory.push_back(m);
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < _inventory.size())
	{
		delete _inventory[idx];
		_inventory.erase(_inventory.begin() + idx);
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < _inventory.size())
		_inventory[idx]->use(target);
}

