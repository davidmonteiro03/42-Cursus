/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:28:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 11:10:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &ref);
		Point& operator=(const Point &ref);
		~Point();

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
