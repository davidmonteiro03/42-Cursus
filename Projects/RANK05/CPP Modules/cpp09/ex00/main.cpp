/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:24:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 13:14:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || (argc == 2 && !*argv[1]))
	{
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange btc(argv[1]);
		// btc.displayInputFile(false);
		btc.displayInputFile(true);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
