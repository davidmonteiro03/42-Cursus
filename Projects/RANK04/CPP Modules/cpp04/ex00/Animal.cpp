/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:51:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:10:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	this->_type = "animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal &ref)
{
	this->_type = ref._type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(Animal const &ref)
{
	this->_type = ref._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}
