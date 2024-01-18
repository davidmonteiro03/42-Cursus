/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:10:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/18 21:31:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : \
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << std::endl;
	std::cout << "ClapTrap default constructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
	std::cout << std::endl;
	std::cout << "ClapTrap copy constructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
	*this = ref;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	std::cout << std::endl;
	std::cout << "ClapTrap assignment operator for " << _name;
	std::cout << " called";
	std::cout << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << std::endl;
	std::cout << "ClapTrap destructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (_name);
}

int ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}


void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << _name;
		std::cout << " is dead!";
		std::cout << std::endl;
		return ;
	}
	if (_energyPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << _name;
		std::cout << " has no energy points!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ClapTrap " << _name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << _attackDamage;
	std::cout << " points of damage!";
	std::cout << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << _name;
		std::cout << " is dead!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ClapTrap " << _name;
	std::cout << " takes " << amount;
	std::cout << " points of damage!";
	std::cout << std::endl;
	_hitPoints -= amount;
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " died!";
		std::cout << std::endl;
		_hitPoints = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "ClapTrap " << _name;
		std::cout << " has no energy points!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ClapTrap " << _name;
	std::cout << " repaired " << amount;
	std::cout << " points for itself!";
	std::cout << std::endl;
	_hitPoints += amount;
	_energyPoints--;
}
