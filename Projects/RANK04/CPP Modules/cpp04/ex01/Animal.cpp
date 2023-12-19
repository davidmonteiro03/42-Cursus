/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:42:58 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:43:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << this->_type << " created" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Default Animal " << this->_type << " created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->_type << " destroyed" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	std::cout << "Animal " << ref._type << " copied to a new Animal";
	std::cout << std::endl;
	*this = ref;
}

Animal&	Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal " << rhs._type << " changed its value";
	std::cout << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "What is Animal " << this->getType();
	std::cout << " saying???" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
