/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:33:01 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/26 22:00:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	// create data_1
	t_data* data_1 = new t_data;
	data_1->name = "data_1";
	data_1->age = 10;
	// create data_2
	t_data* data_2 = new t_data;
	data_2->name = "data_2";
	data_2->age = 20;
	// Original
	std::cout << "Original contents" << std::endl;
	std::cout << "data_1: " << data_1->name << ", " << data_1->age << std::endl;
	std::cout << "data_2: " << data_2->name << ", " << data_2->age << std::endl;
	std::cout << std::endl;
	// Serialize
	uintptr_t data_1_raw = Serializer::serialize(data_1);
	uintptr_t data_2_raw = Serializer::serialize(data_2);
	std::cout << "data_1 raw: " << data_1_raw << std::endl;
	std::cout << "data_2 raw: " << data_2_raw << std::endl;
	std::cout << std::endl;
	// Deserialize
	data_1 = Serializer::deserialize(data_1_raw);
	data_2 = Serializer::deserialize(data_2_raw);
	std::cout << "Deserialize contents" << std::endl;
	std::cout << "data_1: " << data_1->name << ", " << data_1->age << std::endl;
	std::cout << "data_2: " << data_2->name << ", " << data_2->age << std::endl;
	return (0);
}
