/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:07:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/18 21:31:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << std::endl;
	std::cout << "FragTrap default constructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref._name)
{
	std::cout << std::endl;
	std::cout << "FragTrap copy constructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
	*this = ref;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << std::endl;
	std::cout << "FragTrap assignment operator for " << _name;
	std::cout << " called";
	std::cout << std::endl;
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << std::endl;
	std::cout << "FragTrap destructor for " << _name;
	std::cout << " called";
	std::cout << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "FragTrap " << _name;
		std::cout << " has no energy points!";
		std::cout << std::endl;
		return ;
	}
	if (_hitPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "FragTrap " << _name;
		std::cout << " is dead!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "FragTrap " << _name;
	std::cout << " attacks " << target;
	std::cout << ", causing " << _attackDamage;
	std::cout << " points of damage!";
	std::cout << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys()
{
	if (_hitPoints <= 0)
	{
		std::cout << std::endl;
		std::cout << "FragTrap " << _name;
		std::cout << " is dead!";
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "FragTrap " << _name;
	std::cout << " high fives guys.";
	std::cout << std::endl;
}
