/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:51:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 15:21:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat &ref)
{
	this->_type = ref._type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(Cat const &ref)
{
	this->_type = ref._type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Miau miau" << std::endl;
}

std::string	Cat::getType(void) const
{
	return (this->_type);
}
