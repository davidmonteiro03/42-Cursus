/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:17:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/08 11:56:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Vector2.hpp"

Vector2::Vector2(void) : X(0), Y(0) {}

Vector2::Vector2(const float x, const float y) : X(x), Y(y) {}

Vector2::Vector2(const Vector2 &copy) : X(copy.X), Y(copy.Y) {}

Vector2 &Vector2::operator=(const Vector2 &other)
{
	if (this != &other)
	{
		this->X = other.getX();
		this->Y = other.getY();
	}
	return *this;
}

Vector2::~Vector2() {}

float Vector2::getX(void) const { return this->X; }

float Vector2::getY(void) const { return this->Y; }

void Vector2::setX(const float x) { this->X = x; }

void Vector2::setY(const float y) { this->Y = y; }

std::ostream &operator<<(std::ostream &os, const Vector2 &v)
{
	os << "[" << v.getX() << ", " << v.getY() << "]";
	return os;
}
