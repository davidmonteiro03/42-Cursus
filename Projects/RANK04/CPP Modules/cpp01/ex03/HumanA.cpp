/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:15:38 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/05 21:45:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "Human A " << name << " created with ";
	std::cout << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Human A " << this->_name << " deleted" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his ";
	std::cout << this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}
