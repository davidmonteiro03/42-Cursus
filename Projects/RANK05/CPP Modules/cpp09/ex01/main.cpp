/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:40:47 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 15:12:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2 || (argc == 2 && !*argv[1]))
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	RPN _rpn;
	try
	{
		_rpn.parseInput(argv[1]);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
