/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:13:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 11:34:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_fixedpoint = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(ref.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
		this->_fixedpoint = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedpoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedpoint = raw;
}
