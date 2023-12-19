/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 19:11:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << this->_type << " created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << this->_type << " destroyed" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Animal " << this->getType();
	std::cout << " said woof woof" << std::endl;
}
