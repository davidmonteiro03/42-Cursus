/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:35:29 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/04 17:35:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget*>::iterator it = _targets.begin();
	while (it != _targets.end())
	{
		delete it->second;
		++it;
	}
	_targets.clear();
}

void TargetGenerator::learnTargetType(ATarget* target)
{
	if (!target)
		return ;
	if (_targets.find(target->getType()) == _targets.end())
		_targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const std::string& target_type)
{
	std::map<std::string, ATarget*>::iterator it = _targets.find(target_type);
	if (it != _targets.end())
	{
		delete it->second;
		_targets.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(const std::string& target_type)
{
	ATarget* tmp = NULL;
	if (_targets.find(target_type) != _targets.end())
		tmp = _targets[target_type];
	return (tmp);
}
