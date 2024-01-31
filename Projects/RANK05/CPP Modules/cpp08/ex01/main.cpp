/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:37:20 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/31 07:48:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception& e) { std::cerr << e.what() << std::endl; }
	}
/* 	{
		try
		{
			Span sp = Span(5);
			std::vector<int> range;
			range.push_back(6);
			range.push_back(3);
			range.push_back(17);
			range.push_back(9);
			range.push_back(11);
			sp.addNumberRange(range.begin(), range.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception& e) { std::cerr << e.what() << std::endl; }
	} */
	return (0);
}
