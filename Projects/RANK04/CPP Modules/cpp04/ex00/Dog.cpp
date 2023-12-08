/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:51:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:21:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog &ref)
{
	this->_type = ref._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(Dog const &ref)
{
	this->_type = ref._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (this->_type);
}
