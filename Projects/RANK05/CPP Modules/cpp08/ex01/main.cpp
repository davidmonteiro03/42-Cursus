/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:37:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/28 19:55:12 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::srand(std::time(NULL));
	Span span(2 * 5 + 1);
	for (int i = 0; i < 2 * 5 + 1; i++)
	{
		int num = std::rand() % 11 - 5;
		span.addNumber(num);
		std::cout << num << std::endl;
	}
	std::cout << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	return (0);
}
