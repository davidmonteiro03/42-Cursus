/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:19:54 by dcaetano          #+#    #+#             */
/*   Updated: 2024/10/22 13:09:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, const char *argv[])
{
	std::string input_file = "";
	if (argc > 1)
		input_file = argv[1];
	try
	{
		BitcoinExchange btc;
		btc._execute(input_file);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (void)argc, (void)argv, 0;
}
