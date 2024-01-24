/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:35:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 09:01:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		AForm* form = new ShrubberyCreationForm();
		try
		{
			Bureaucrat bc("bc", 137);
			try
			{
				bc.signForm(*form);
				std::cout << std::endl;
				try
				{
					form->execute(bc);
				}
				catch(std::exception& e)
				{
					std::cout << "Error! " << e.what() << std::endl;
				}
			}
			catch(std::exception& e)
			{
				std::cout << "Error! " << e.what() << std::endl;
			}
		}
		catch(std::exception& e)
		{
			std::cout << "Error! " << e.what() << std::endl;
		}
		delete form;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl;
	}
	return (0);
}
