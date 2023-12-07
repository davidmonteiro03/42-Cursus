/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:45:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 12:25:51 by dcaetano         ###   ########.fr       */
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
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream & operator<<(std::ostream & out, Fixed const & in);

#endif
