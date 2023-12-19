/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:28:15 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:46:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("aanimal")
{
	std::cout << this->_type << " created" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Default AAnimal " << this->_type << " created" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal " << this->_type << " destroyed" << std::endl;
}

AAnimal::AAnimal(const AAnimal &ref)
{
	std::cout << "AAnimal " << ref._type << " copied to a new aanimal";
	std::cout << std::endl;
	*this = ref;
}

AAnimal&	AAnimal::operator=(const AAnimal &rhs)
{
	std::cout << "AAnimal " << rhs._type << " changed its value";
	std::cout << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << "What is AAnimal " << this->getType();
	std::cout << " saying???" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
