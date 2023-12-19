/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 20:46:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	std::cout << this->_type << " created" << std::endl;
	this->_brain = new Brain();
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << this->_type << " destroyed" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "AAnimal " << this->getType();
	std::cout << " said miau miau" << std::endl;
}
