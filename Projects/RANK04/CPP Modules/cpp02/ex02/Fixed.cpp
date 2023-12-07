/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:13:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 13:21:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedpoint(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedpoint(n << _fractionalbits)
{
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedpoint(roundf(n * (1 << this->_fractionalbits)))
{
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed& Fixed::operator=(const Fixed &ref)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &ref)
		this->_fixedpoint = ref.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

// comparison operators

bool	Fixed::operator>(const Fixed &ref) const
{
	return (this->toFloat() > ref.toFloat());
}

bool	Fixed::operator<(const Fixed &ref) const
{
	return (this->toFloat() < ref.toFloat());
}

bool	Fixed::operator>=(const Fixed &ref) const
{
	return (this->toFloat() >= ref.toFloat());
}

bool	Fixed::operator<=(const Fixed &ref) const
{
	return (this->toFloat() <= ref.toFloat());
}

bool	Fixed::operator==(const Fixed &ref) const
{
	return (this->toFloat() == ref.toFloat());
}

bool	Fixed::operator!=(const Fixed &ref) const
{
	return (this->toFloat() != ref.toFloat());
}

// arithmetic operators

Fixed	Fixed::operator+(const Fixed &ref)
{
	return Fixed(this->toFloat() + ref.toFloat());
}

Fixed	Fixed::operator-(const Fixed &ref)
{
	return Fixed(this->toFloat() - ref.toFloat());
}

Fixed	Fixed::operator*(const Fixed &ref)
{
	return Fixed(this->toFloat() * ref.toFloat());
}

Fixed	Fixed::operator/(const Fixed &ref)
{
	return Fixed(this->toFloat() / ref.toFloat());
}

// increment/decrement operators

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	tmp._fixedpoint = this->_fixedpoint++;
	return (*this);
}

Fixed&	Fixed::operator++(void)
{
	++this->_fixedpoint;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	tmp._fixedpoint = this->_fixedpoint--;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--this->_fixedpoint;
	return (*this);
}

// min/max

Fixed&	Fixed::min(Fixed &ref1, Fixed &ref2)
{
	if (ref1.toFloat() < ref2.toFloat())
		return (ref1);
	return (ref2);
}

const Fixed&	Fixed::min(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.toFloat() < ref2.toFloat())
		return (ref1);
	return (ref2);
}

Fixed&	Fixed::max(Fixed &ref1, Fixed &ref2)
{
	if (ref1.toFloat() > ref2.toFloat())
		return (ref1);
	return (ref2);
}

const Fixed&	Fixed::max(const Fixed &ref1, const Fixed &ref2)
{
	if (ref1.toFloat() > ref2.toFloat())
		return (ref1);
	return (ref2);
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
