/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:15:04 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/02 22:15:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type) {}

ATarget::~ATarget() {}

const std::string& ATarget::getType(void) const { return (_type); }

void ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << _type;
	std::cout << " has been ";
	std::cout << spell.getEffects();
	std::cout << "!";
	std::cout << std::endl;
}
