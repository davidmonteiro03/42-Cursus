/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:40:46 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 20:19:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "PhoneBook_utils.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
	std::cout << \
		"Welcome. There was created an empty phonebook for up to 8 contacts." \
		<< std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "All contacts from phonebook were removed. See you next time." \
		<< std::endl;
}

void	PhoneBook::add_contact(void)
{
	std::string	str;

	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::endl << "What's your first name?" << std::endl << "R: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_first_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::endl << "What's your last name, ";
		std::cout << this->contacts[this->index % 8].get_first_name();
		std::cout << "?" << std::endl << "R: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_last_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::endl << "What's your phone number, ";
		std::cout << this->contacts[this->index % 8].get_first_name();
		std::cout << "?" << std::endl << "R: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_phone_number(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::endl << "What's your nickname, ";
		std::cout << this->contacts[this->index % 8].get_first_name();
		std::cout << "?" << std::endl << "R: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_nickname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::endl << "What's your darkest secret, ";
		std::cout << this->contacts[this->index % 8].get_first_name();
		std::cout << "?" << std::endl << "R: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->contacts[this->index % 8].set_darkest_secret(str);
			std::cout << "This contact was added to phonebook." \
				<< std::endl;
		}
	}
	this->index++;
}

void	PhoneBook::print_contact(Contact contact)
{
	std::cout << std::endl << "Information of this contact:" << std::endl;
	if (!contact.get_first_name().size())
	{
		std::cout << std::endl << "Error searching contact..." << std::endl;
		return ;
	}
	std::cout << std::endl << "First Name: " << contact.get_first_name();
	std::cout << std::endl << "Last Name: " << contact.get_last_name();
	std::cout << std::endl << "Phone Number: " << contact.get_phone_number();
	std::cout << std::endl << "Nickname: " << contact.get_nickname();
	std::cout << std::endl << "Darkest Secret: " << contact.get_darkest_secret();
	std::cout << std::endl;
}

Contact	PhoneBook::get_contact(int index)
{
	return (this->contacts[index % 8]);
}

void	PhoneBook::search_contact(void)
{
	std::string	str;

	if (!search_contact_util(this->contacts))
	{
		std::cout << "Phone Book is empty." << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Enter an index to look for: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
				this->contacts[str[0] - 1 - '0'].get_first_name().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index. Try again." << std::endl;
	}
	if (!std::cin.eof())
		this->print_contact(this->contacts[str[0] - 1 - '0']);
}
