/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:50:13 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 20:31:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_utils.hpp"

void	print_trunc(std::string str)
{
	if (str.size() > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << (char)str[i];
		std::cout << ".";
	}
	else
	{
		for (int i = (int)str.size(); i < 10; i++)
			std::cout << " ";
		for (int i = 0; i < (int)str.size(); i++)
			std::cout << (char)str[i];
	}
}

int	search_contact_util(Contact contacts[8])
{
	char	c;
	int		i;

	if (!contacts[0].get_first_name().size())
		return (0);
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	c = '0';
	i = 0;
	while (++c <= '8')
	{
		if (contacts[c - 1 - '0'].get_first_name().size() && ++i)
		{
			std::cout << "|";
			std::cout << "         " << (char)(i + '0') << "|";
			print_trunc(contacts[c - 1 - '0'].get_first_name());
			std::cout << "|";
			print_trunc(contacts[c - 1 - '0'].get_last_name());
			std::cout << "|";
			print_trunc(contacts[c - 1 - '0'].get_nickname());
			std::cout << "|" << std::endl;
		}
	}
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return (i);
}
