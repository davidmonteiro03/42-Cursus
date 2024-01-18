/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:07:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/18 21:24:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << std::endl;
	std::cout << "ScavTrap default constructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref._name)
{
	std::cout << std::endl;
	std::cout << "ScavTrap copy constructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
	*this = ref;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	std::cout << std::endl;
	std::cout << "ScavTrap assignment operator for " << _name;
	std::cout << " called";
	std::cout << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << std::endl;
	std::cout << "ScavTrap destructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << _name;
		std::cout << " has no energy points!";
		std::cout << std::endl;
		return ;
	}
	if (_hitPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << _name;
		std::cout << " is dead!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ScavTrap " << _name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << _attackDamage;
	std::cout << " points of damage!";
	std::cout << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate()
{
	if (_hitPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "ScavTrap " << _name;
		std::cout << " is dead!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ScavTrap " << _name;
	std::cout << " is now in Gate keeper mode.";
	std::cout << std::endl;
}
