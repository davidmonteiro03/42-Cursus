/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:18:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/02 22:18:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : \
	_name(name), _effects(effects) {}

ASpell::~ASpell() {}

std::string ASpell::getName(void) const { return (_name); }

std::string ASpell::getEffects(void) const { return (_effects); }

void ASpell::launch(const ATarget& target) const { target.getHitBySpell(*this); }
