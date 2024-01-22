/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:48:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/22 18:53:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void separator(bool lines)
{
	if (lines)
	{
		std::cout << "=====================================================";
		std::cout << "=====================================================";
	}
	std::cout << std::endl << std::endl;
}

void default_2_wrong(void)
{
	// wrong_high
	separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR_2->wrong_high => ";
		Bureaucrat wrong_high("wrong_high", 0);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	separator(false);
	// wrong_low
	separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR_2->wrong_low => ";
		Bureaucrat wrong_low("wrong_low", 151);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	separator(false);
}

void default_2_right(void)
{
	// right_high
	separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR_2->right_high => ";
		Bureaucrat right_high("right_high", 1);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
	// right_low
	separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR_2->right_low => ";
		Bureaucrat right_low("right_low", 150);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
}

void copy(void)
{
	Bureaucrat base("base", 100);
	// copy_1
	separator(true);
	try
	{
		std::cout << "TEST_COPY_CONSTRUCTOR->copy_1 => ";
		Bureaucrat copy_1(base);
		std::cout << "Success! " << std::endl << std::endl;
		if (copy_1.getName() != base.getName() || \
			copy_1.getGrade() != base.getGrade())
			std::cout << "Result: KO!";
		else
			std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
}

void assignment(void)
{
	Bureaucrat base("base", 125);
	// assignment_1
	separator(true);
	Bureaucrat assignment_1("assignment_1", 85);
	try
	{
		std::cout << "TEST_ASSIGNMENT_OVERLOAD->assignment_1 => ";
		assignment_1 = base;
		std::cout << "Success! " << std::endl << std::endl;
		if (assignment_1.getName() == base.getName() || \
			assignment_1.getGrade() != base.getGrade())
			std::cout << "Result: KO!";
		else
			std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
	// assignment_2
	separator(true);
	Bureaucrat assignment_2("assignment_2", 85);
	try
	{
		std::cout << "TEST_ASSIGNMENT_OVERLOAD->assignment_2 => ";
		base = assignment_2;
		std::cout << "Success! " << std::endl << std::endl;
		if (base.getName() == assignment_2.getName() || \
			base.getGrade() != assignment_2.getGrade())
			std::cout << "Result: KO!";
		else
			std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
}

void high_operations(void)
{
	// high_1
	separator(true);
	Bureaucrat high_1("high_1", 1);
	try
	{
		std::cout << "TEST_OPERATIONS->high_operations->high_1->incrementGrade() => ";
		high_1.incrementGrade();
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	separator(false);
	try
	{
		std::cout << "TEST_OPERATIONS->high_operations->high_1->decrementGrade() => ";
		int old = high_1.getGrade();
		high_1.decrementGrade();
		std::cout << "Success! " << std::endl << std::endl;
		if (high_1.getGrade() == old + 1)
			std::cout << "Result: OK!";
		else
			std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
}

void low_operations(void)
{
	// low_1
	separator(true);
	Bureaucrat low_1("low_1", 150);
	try
	{
		std::cout << "TEST_OPERATIONS->low_operations->low_1->decrementGrade() => ";
		low_1.decrementGrade();
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	separator(false);
	try
	{
		std::cout << "TEST_OPERATIONS->low_operations->low_1->incrementGrade() => ";
		int old = low_1.getGrade();
		low_1.incrementGrade();
		std::cout << "Success! " << std::endl << std::endl;
		if (low_1.getGrade() == old - 1)
			std::cout << "Result: OK!";
		else
			std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
}

void _default(void)
{
	separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->_default->test => ";
		Bureaucrat test;
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	separator(false);
}

int	main(void)
{
	// TEST_DEFAULT_CONSTRUCTOR
	_default();
	// TEST_DEFAULT_CONSTRUCTOR_2
	default_2_wrong();
	default_2_right();
	// TEST_COPY_CONSTRUCTOR
	copy();
	// TEST_ASSIGNMENT_OVERLOAD
	assignment();
	// TEST_OPERATIONS
	low_operations();
	high_operations();
	return (0);
}
