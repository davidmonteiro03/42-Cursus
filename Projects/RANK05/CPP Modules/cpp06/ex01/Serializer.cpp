/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:29:29 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/26 21:48:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) { *this = copy; }

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
		;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(t_data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data*>(raw));
}
