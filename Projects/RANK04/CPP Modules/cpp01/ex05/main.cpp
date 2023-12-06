/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:48:02 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 09:26:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	level;
	Harl	Harl;

	while (1)
	{
		std::cout << "Enter a level: ";
		std::getline(std::cin, level);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
		Harl.complain(level);
	}
	return (0);
}
