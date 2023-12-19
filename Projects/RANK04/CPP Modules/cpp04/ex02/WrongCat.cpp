/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:08:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/19 19:59:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << this->_type << " created" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->_type << " destroyed" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Animal " << this->getType();
	std::cout << " said meooowwwww. It's not a cat." << std::endl;
}
