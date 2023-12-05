/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:27:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/05 08:17:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "PhoneBook_utils.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook	myphonebook;
	std::string	str;

	while (1)
	{
		std::cout << std::endl << "Option: ";
		std::getline(std::cin, str);
		if (std::cin.eof() || str == "EXIT")
		{
			if (std::cin.eof())
				std::cout << std::endl;
			break ;
		}
		if (str == "ADD")
			myphonebook.add_contact();
		else if (str == "SEARCH")
			myphonebook.search_contact();
	}
	return (0);
}
