/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:13:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 12:25:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedpoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedpoint(n << _fractionalbits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedpoint(roundf(n * (1 << this->_fractionalbits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
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
	return (this->_fixedpoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedpoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractionalbits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedpoint >> _fractionalbits);
}

std::ostream & operator<<(std::ostream & out, Fixed const & in)
{
	out << in.toFloat();
	return (out);
}
