/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:00:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 11:30:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_fixedpoint;
		static const int	_fractionalbits = 8;
	public:
		Fixed();
		Fixed(const Fixed &ref);
		Fixed& operator=(const Fixed &ref);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
