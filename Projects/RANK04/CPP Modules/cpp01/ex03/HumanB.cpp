/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:15:38 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/05 21:46:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL)
{
	this->_name = name;
	std::cout << "Human B " << name << " created without weapon" << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Human B " << this->_name << " deleted" << std::endl;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his ";
	std::cout << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
