/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:36:11 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 13:01:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &ref) : _x(ref._x), _y(ref._y)
{
}

Point&	Point::operator=(const Point &ref)
{
	if (this != &ref)
	{
		(Fixed)this->_x = ref.getX();
		(Fixed)this->_y = ref.getY();
	}
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}
