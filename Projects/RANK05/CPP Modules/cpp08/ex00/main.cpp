/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:29:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/28 18:42:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

#define NUM_ELEM 10
#define SEARCH_E 10

int main(void)
{
	std::vector<int> _vector;
	for (int i = 0; i < NUM_ELEM; i++)
		_vector.push_back(i + 1);
	std::vector<int>::iterator it = ::easyfind(_vector, SEARCH_E);
	if (it != _vector.end())
		std::cout << *it << " belongs to the vector! :)" << std::endl;
	else
		std::cout << SEARCH_E << " doesn't belong to the vector... :(" << std::endl;
	return (0);
}
