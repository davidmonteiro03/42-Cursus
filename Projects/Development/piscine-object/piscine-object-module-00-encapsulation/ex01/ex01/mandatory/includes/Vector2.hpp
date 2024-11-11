/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector2.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 09:15:04 by dcaetano          #+#    #+#             */
/*   Updated: 2024/11/10 16:43:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

class Vector2
{
public:
	Vector2(void);
	Vector2(const float, const float);
	Vector2(const Vector2 &);
	Vector2 &operator=(const Vector2 &);
	~Vector2();
	float getX(void) const;
	float getY(void) const;
	void setX(const float);
	void setY(const float);

private:
	float X, Y;
};

std::ostream &operator<<(std::ostream &, const Vector2 &);

#endif // !VECTOR2_HPP
