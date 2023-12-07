/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:34:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 13:51:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

static Fixed	area(Point const a, Point const b, Point const c)
{
	return ((a.getX() * (b.getY() - c.getY()) + \
			b.getX() * (c.getY() - a.getY()) + \
			c.getX() * (a.getY() - b.getY())) / 2);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area_abc = abs(area(a, b, c));
	Fixed	area_pab = abs(area(point, a, b));
	Fixed	area_pac = abs(area(point, a, c));
	Fixed	area_pbc = abs(area(point, b, c));

	if (point.getX() == a.getX() && point.getY() == a.getY())
		return (false);
	if (point.getX() == b.getX() && point.getY() == b.getY())
		return (false);
	if (point.getX() == c.getX() && point.getY() == c.getY())
		return (false);
	if (area_abc == 0 || area_pab == 0 || area_pac == 0 || area_pbc == 0)
		return (false);
	return (area_pab + area_pac + area_pbc == area_abc);
}
