/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:37:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 20:34:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span sp = Span(5);
	std::vector<int> range;

	sp.addNumber(6);
	sp.addNumber(2);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	range.push_back(67);
	range.push_back(34);
	range.push_back(35);
	range.push_back(20);
	range.push_back(90);
	sp.shortestSpan();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	sp.addNumberRange(range.begin(), range.end());
	sp.shortestSpan();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
