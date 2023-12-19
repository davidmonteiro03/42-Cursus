/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:46:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog")
{
	std::cout << this->_type << " created" << std::endl;
	this->_brain = new Brain();
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << this->_type << " destroyed" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "AAnimal " << this->getType();
	std::cout << " said woof woof" << std::endl;
}
