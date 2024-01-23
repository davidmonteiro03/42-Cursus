/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:37:52 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/23 19:18:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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

static void _revert(std::string* name, \
	std::string *_result, std::string *_result_rev)
{
	if (name) *name = "wrong";
	if (_result) *_result = "KO";
	if (_result_rev) *_result_rev = "OK";
}

void _default(void)
{
	_separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->_default->test => ";
		Form test;
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_default(bool result, const int signGrade, const int execGrade)
{
	_separator(true);
	static int right = 0, wrong = 0;
	std::string name = "right", _result = "OK", _result_rev = "KO";
	std::cout << "TEST_DEFAULT_CONSTRUCTOR_2->";
	if (!result)
	{
		_revert(&name, &_result, &_result_rev);
		std::cout << name << "_" << ++wrong << " => ";
	}
	else
		std::cout << name << "_" << ++right << " => ";
	try
	{
		Form test(name, signGrade, execGrade);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: " << _result << "!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: " << _result_rev << "!";
	}
	_separator(false);
}

void _test_copy(void)
{
	Form form;
	_separator(true);
	std::cout << "TEST_COPY_CONSTRUCTOR => ";
	try
	{
		Form test(form);
		std::cout << "Success! " << std::endl << std::endl;
		if (test.getName() != form.getName() || \
			test.getStatus() != form.getStatus() || \
			test.getSignGrade() != form.getSignGrade() || \
			test.getExecGrade() != form.getExecGrade())
			std::cout << "Result: KO!";
		else
			std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_assignment(void)
{
	Form form;
	_separator(true);
	Form assignment("assignment", 100, 65);
	std::cout << "TEST_ASSIGNMENT_OVERLOAD => ";
	try
	{
		assignment = form;
		std::cout << "Success! " << std::endl << std::endl;
		if (assignment.getName() != form.getName() && \
			assignment.getSignGrade() != form.getSignGrade() && \
			assignment.getExecGrade() != form.getExecGrade())
			std::cout << "Result: OK!";
		else
			std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_sign(bool result_bc, bool result_form, const int grade, \
	int* right_bc, int* wrong_bc, int* right_form, int* wrong_form)
{
	_separator(true);
	std::string name_bc = "right", _result_bc = "OK", _result_bc_rev = "KO";
	std::stringstream bc_name;
	std::cout << "TEST_SIGNING->";
	if (!result_bc)
	{
		_revert(&name_bc, &_result_bc, &_result_bc_rev);
		bc_name << name_bc << "_" << ++(*wrong_bc);
	}
	else
		bc_name << name_bc << "_" << ++(*right_bc);
	std::cout << bc_name.str();
	try
	{
		Bureaucrat test(bc_name.str(), grade);
		std::string name_form = "right";
		std::stringstream form_name;
		if (!result_form)
		{
			_revert(&name_form, NULL, NULL);
			form_name << name_form << "_" << ++(*wrong_form);
			std::cout << "->" << form_name.str() << " => ";
			Form form(form_name.str(), 80, 50);
			test.signForm(form);
			std::cout << std::endl << std::endl;
			std::cout << "Result: ";
			if (!form.getStatus())
				std::cout << "OK";
			else
				std::cout << "KO";
			std::cout << "!";
		}
		else
		{
			form_name << name_form << "_" << ++(*right_form);
			std::cout << "->" << form_name.str() << " => ";
			Form form(form_name.str(), 80, 50);
			test.signForm(form);
			std::cout << std::endl << std::endl;
			std::cout << "Result: ";
			if (form.getStatus())
				std::cout << "OK";
			else
				std::cout << "KO";
			std::cout << "!";
		}
	}
	catch(std::exception& e)
	{
		std::cout << " => Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: " << _result_bc_rev << "!";
	}
	_separator(false);
}

void _test_double_sign_1(void)
{
	_separator(true);
	Form form("form", 80, 40);
	Bureaucrat bc_1("bc_1", 80);
	std::cout << "TEST_DOUBLE_SIGNING->form_1->bc_1->sign_first => ";
	try
	{
		form.beSigned(bc_1);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: OK!" << std::endl << std::endl;
		std::cout << "TEST_DOUBLE_SIGNING->form_1->bc_1->sign_again => ";
		try
		{
			form.beSigned(bc_1);
			std::cout << "Success!" << std::endl << std::endl;
			std::cout << "Result: KO!";
		}
		catch(std::exception& e)
		{
			std::cout << "Error! " << e.what() << std::endl << std::endl;
			std::cout << "Result: OK!";
		}
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_double_sign_2(void)
{
	_separator(true);
	Form form("form", 80, 40);
	Bureaucrat bc_1("bc_1", 80);
	Bureaucrat bc_2("bc_2", 80);
	std::cout << "TEST_DOUBLE_SIGNING->form_2->bc_1->sign_first => ";
	try
	{
		form.beSigned(bc_1);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: OK!" << std::endl << std::endl;
		std::cout << "TEST_DOUBLE_SIGNING->form_2->bc_2->sign_first => ";
		try
		{
			form.beSigned(bc_2);
			std::cout << "Success!" << std::endl << std::endl;
			std::cout << "Result: KO!";
		}
		catch(std::exception& e)
		{
			std::cout << "Error! " << e.what() << std::endl << std::endl;
			std::cout << "Result: OK!";
		}
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_double_sign_3(void)
{
	_separator(true);
	Form form("form", 80, 40);
	Bureaucrat bc_1("bc_1", 81);
	Bureaucrat bc_2("bc_2", 80);
	std::cout << "TEST_DOUBLE_SIGNING->form_3->bc_1->sign_first => ";
	try
	{
		form.beSigned(bc_1);
		std::cout << "Success!" << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: OK!" << std::endl << std::endl;
		std::cout << "TEST_DOUBLE_SIGNING->form_3->bc_2->sign_first => ";
		try
		{
			form.beSigned(bc_2);
			std::cout << "Success!" << std::endl << std::endl;
			std::cout << "Result: OK!";
		}
		catch(std::exception& e)
		{
			std::cout << "Error! " << e.what() << std::endl << std::endl;
			std::cout << "Result: KO!" << std::endl << std::endl;
		}
	}
	_separator(false);
}

void _test_double_sign(void)
{
	_test_double_sign_1();
	_test_double_sign_2();
	_test_double_sign_3();
}

int	main(void)
{
	// TEST_DEFAULT_CONSTRUCTOR
	_default();
	// TEST_DEFAULT_CONSTRUCTOR_2
	_test_default(false, 0  , 0  );	//  high | high  -> invalid => false
	_test_default(false, 0  , 1  );	//  high | valid -> invalid => false
	_test_default(false, 0  , 150);	//  high | valid -> invalid => false
	_test_default(false, 0  , 151);	//  high | low   -> invalid => false
	_test_default(false, 1  , 0  );	// valid | high  -> invalid => false
	_test_default(true , 1  , 1  );	// valid | valid ->   valid => true
	_test_default(true , 1  , 150);	// valid | valid ->   valid => true
	_test_default(false, 1  , 151);	// valid | low   -> invalid => false
	_test_default(false, 150, 0  );	// valid | high  -> invalid => false
	_test_default(true , 150, 1  );	// valid | valid ->   valid => true
	_test_default(true , 150, 150);	// valid | valid ->   valid => true
	_test_default(false, 150, 151);	// valid | low   -> invalid => false
	_test_default(false, 151, 0  );	//   low | high  -> invalid => false
	_test_default(false, 151, 1  );	//   low | valid -> invalid => false
	_test_default(false, 151, 150);	//   low | valid -> invalid => false
	_test_default(false, 151, 151);	//   low | low   -> invalid => false
	// TEST_COPY_CONSTRUCTOR
	_test_copy();
	// TEST_ASSIGNMENT_OVERLOAD
	_test_assignment();
	// TEST_SIGNING
	// NOTE: lowest note possible is 80
	int right_bc = 0, wrong_bc = 0;
	int right_form = 0, wrong_form = 0;
	_test_sign(false, false, 0, \
		&right_bc, &wrong_bc, &right_form, &wrong_form);
	_test_sign(true, true, 1, \
		&right_bc, &wrong_bc, &right_form, &wrong_form);
	_test_sign(true, true, 80, \
		&right_bc, &wrong_bc, &right_form, &wrong_form);
	_test_sign(true, false, 81, \
		&right_bc, &wrong_bc, &right_form, &wrong_form);
	_test_sign(true, false, 150, \
		&right_bc, &wrong_bc, &right_form, &wrong_form);
	_test_sign(false, false, 151, \
		&right_bc, &wrong_bc, &right_form, &wrong_form);
	// TEST_DOUBLE_SIGNING (test only if your Form class has a AlreadySignedException)
	_test_double_sign();
	return (0);
}
