/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:45:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 13:16:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_fixedpoint;
		static const int	_fractionalbits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &ref);
		Fixed(const int n);
		Fixed(const float n);
		Fixed& operator=(const Fixed &ref);
		~Fixed();

		// comparison operators
		bool operator>(const Fixed &ref) const;
		bool operator<(const Fixed &ref) const;
		bool operator>=(const Fixed &ref) const;
		bool operator<=(const Fixed &ref) const;
		bool operator==(const Fixed &ref) const;
		bool operator!=(const Fixed &ref) const;

		// arithmetic operators
		Fixed operator+(const Fixed &ref);
		Fixed operator-(const Fixed &ref);
		Fixed operator*(const Fixed &ref);
		Fixed operator/(const Fixed &ref);

		// increment/decrement operators
		Fixed operator++(int);
		Fixed& operator++(void);
		Fixed operator--(int);
		Fixed& operator--(void);

		// min/max
		static Fixed&		min(Fixed &ref1, Fixed &ref2);
		static const Fixed&	min(const Fixed &ref1, const Fixed &ref2);
		static Fixed&		max(Fixed &ref1, Fixed &ref2);
		static const Fixed&	max(const Fixed &ref1, const Fixed &ref2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream & operator<<(std::ostream & out, Fixed const & in);

#endif
