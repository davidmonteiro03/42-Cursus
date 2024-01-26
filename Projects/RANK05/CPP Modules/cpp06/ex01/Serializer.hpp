/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:25:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/26 21:36:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct s_data
{
	std::string name;
	double age;
}t_data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& other);
	public:
		~Serializer();
		static uintptr_t serialize(t_data* ptr);
		static t_data* deserialize(uintptr_t raw);
};

#endif
