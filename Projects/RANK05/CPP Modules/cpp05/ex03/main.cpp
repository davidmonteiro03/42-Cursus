/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:47:02 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 17:19:44 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <sstream>

static void _separator(bool lines)
{
	if (lines)
	{
		std::cout << "=====================================================";
		std::cout << "=====================================================";
		std::cout << "=====================================================";
	}
	std::cout << std::endl << std::endl;
}

static void _test_forms_making(bool result, std::string form_name)
{
	_separator(true);
	static int i = 0;
	std::stringstream test_name;
	test_name << "test_" << ++i;
	std::cout << "TEST_FORMS_MAKING->" << test_name.str() << " => ";
	Intern someRandomIntern;
	Form* rrf;
	try
	{
		rrf = someRandomIntern.makeForm(form_name, test_name.str());
		std::cout << " -> Success!" << std::endl << std::endl;
		std::cout << "Result: ";
		if (result)
			std::cout << "OK";
		else
			std::cout << "KO";
		std::cout << "!";
		delete rrf;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: ";
		if (!result)
			std::cout << "OK";
		else
			std::cout << "KO";
		std::cout << "!";
	}
	_separator(false);
}

int	main(void)
{
	// TEST_FORMS_MAKING
	// valid names:
	// 		"shrubbery creation"
	// 		"robotomy request"
	// 		"presidential pardon"
	_test_forms_making(false, "invalid"            );
	_test_forms_making(true , "shrubbery creation" );
	_test_forms_making(true , "robotomy request"   );
	_test_forms_making(true , "presidential pardon");
	return (0);
}
