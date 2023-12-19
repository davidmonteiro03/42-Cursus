/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 19:46:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << this->_type << " created" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << this->_type << " destroyed" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Animal " << this->getType();
	std::cout << " said miau miau" << std::endl;
}
