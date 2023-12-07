/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:43:05 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 18:35:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(0), \
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref)
{
	*this = ref;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " does not have energy points";
		std::cout << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
	std::cout << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= amount)
	{
		std::cout << "ClapTrap " << _name << " does not have hit points";
		std::cout << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " takes " << amount;
	std::cout << " of damage" << std::endl;
	_energyPoints--;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " does not have energy points";
		std::cout << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " repairs itself for " << amount;
	std::cout << " hit points!" << std::endl;
	_energyPoints--;
	_hitPoints += amount;
}
