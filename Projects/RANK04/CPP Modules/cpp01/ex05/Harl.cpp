/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:53:26 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 09:28:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-";
	std::cout << "ketchup burger. I really do!";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn't put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn't be asking for more!";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working ";
	std::cout << "here since last month.";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.";
}

void	Harl::complain(std::string level)
{
	t_func	funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	while (i < 4 && levels[i].compare(level))
		i++;
	if (i < 4)
	{
		std::cout << std::endl;
		(this->*funcs[i])();
		std::cout << std::endl << std::endl;
	}
}
