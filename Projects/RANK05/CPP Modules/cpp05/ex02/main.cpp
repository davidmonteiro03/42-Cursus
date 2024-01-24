/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:35:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 15:53:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <sstream>

#define BGRN "\033[1;32m"
#define BRED "\033[1;31m"
#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define BCYN "\033[1;36m"
#define RESET "\033[0m"

static int i = 0;
static int const_try = 0;
static int tests_try = 0;
static int const_oks = 0;
static int tests_oks = 0;

static void _separator(bool lines)
{
	if (lines)
	{
		std::cout << RESET "=====================================================";
		std::cout << "=====================================================";
		std::cout << "=====================================================";
	}
	std::cout << std::endl << std::endl;
}

void _default_ShrubberyCreationForm(void)
{
	++const_try;
	_separator(true);
	try
	{
		std::cout << BCYN "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_ShrubberyCreationForm->shrubbery" << RESET " => ";
		AForm* shrubbery = new ShrubberyCreationForm();
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
		delete shrubbery;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	_separator(false);
}

void _test_default_ShrubberyCreationForm(std::string target)
{
	++const_try;
	_separator(true);
	try
	{
		std::cout << BCYN "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_ShrubberyCreationForm->";
		std::cout << target << RESET " => ";
		AForm* shrubbery = new ShrubberyCreationForm(target);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
		delete shrubbery;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	_separator(false);
}

void _test_copy_ShrubberyCreationForm(void)
{
	++const_try;
	AForm* shrubbery = new ShrubberyCreationForm();
	_separator(true);
	std::cout << BCYN "TEST_COPY_CONSTRUCTOR_ShrubberyCreationForm" << RESET " => ";
	try
	{
		AForm* test(shrubbery);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		if (test->getName() != shrubbery->getName() || \
			test->getStatus() != shrubbery->getStatus() || \
			test->getSignGrade() != shrubbery->getSignGrade() || \
			test->getExecGrade() != shrubbery->getExecGrade())
			std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
		else
		{
			std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
			++const_oks;
		}
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	delete shrubbery;
	_separator(false);
}

void _test_assignment_ShrubberyCreationForm(void)
{
	++const_try;
	AForm* shrubbery = new ShrubberyCreationForm();
	_separator(true);
	AForm* assignment = new ShrubberyCreationForm("assignment");
	std::cout << BCYN "TEST_ASSIGNMENT_OVERLOAD_ShrubberyCreationForm" << RESET " => ";
	try
	{
		*assignment = *shrubbery;
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	delete assignment;
	delete shrubbery;
	_separator(false);
}

void _default_RobotomyRequestForm(void)
{
	++const_try;
	_separator(true);
	try
	{
		std::cout << BCYN "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_RobotomyRequestForm->shrubbery" << RESET " => ";
		AForm* robotmy = new RobotomyRequestForm();
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
		delete robotmy;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	_separator(false);
}

void _test_default_RobotomyRequestForm(std::string target)
{
	++const_try;
	_separator(true);
	try
	{
		std::cout << BCYN "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_RobotomyRequestForm->";
		std::cout << target << RESET " => ";
		AForm* robotmy = new RobotomyRequestForm(target);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
		delete robotmy;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	_separator(false);
}

void _test_copy_RobotomyRequestForm(void)
{
	++const_try;
	AForm* robotmy = new RobotomyRequestForm();
	_separator(true);
	std::cout << BCYN "TEST_COPY_CONSTRUCTOR_RobotomyRequestForm" << RESET " => ";
	try
	{
		AForm* test(robotmy);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		if (test->getName() != robotmy->getName() || \
			test->getStatus() != robotmy->getStatus() || \
			test->getSignGrade() != robotmy->getSignGrade() || \
			test->getExecGrade() != robotmy->getExecGrade())
			std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
		else
		{
			std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
			++const_oks;
		}
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	delete robotmy;
	_separator(false);
}

void _test_assignment_RobotomyRequestForm(void)
{
	++const_try;
	AForm* robotmy = new RobotomyRequestForm();
	_separator(true);
	AForm* assignment = new RobotomyRequestForm("assignment");
	std::cout << BCYN "TEST_ASSIGNMENT_OVERLOAD_RobotomyRequestForm" << RESET " => ";
	try
	{
		*assignment = *robotmy;
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	delete assignment;
	delete robotmy;
	_separator(false);
}

void _default_PresidentialPardonForm(void)
{
	++const_try;
	_separator(true);
	try
	{
		std::cout << BCYN "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_PresidentialPardonForm->shrubbery" << RESET " => ";
		AForm* presidential = new PresidentialPardonForm();
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
		delete presidential;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	_separator(false);
}

void _test_default_PresidentialPardonForm(std::string target)
{
	++const_try;
	_separator(true);
	try
	{
		std::cout << BCYN "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_PresidentialPardonForm->";
		std::cout << target << RESET " => ";
		AForm* presidential = new PresidentialPardonForm(target);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
		delete presidential;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	_separator(false);
}

void _test_copy_PresidentialPardonForm(void)
{
	++const_try;
	AForm* presidential = new PresidentialPardonForm();
	_separator(true);
	std::cout << BCYN "TEST_COPY_CONSTRUCTOR_PresidentialPardonForm" << RESET " => ";
	try
	{
		AForm* test(presidential);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		if (test->getName() != presidential->getName() || \
			test->getStatus() != presidential->getStatus() || \
			test->getSignGrade() != presidential->getSignGrade() || \
			test->getExecGrade() != presidential->getExecGrade())
			std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
		else
		{
			std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
			++const_oks;
		}
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	delete presidential;
	_separator(false);
}

void _test_assignment_PresidentialPardonForm(void)
{
	++const_try;
	AForm* presidential = new PresidentialPardonForm();
	_separator(true);
	AForm* assignment = new PresidentialPardonForm("assignment");
	std::cout << BCYN "TEST_ASSIGNMENT_OVERLOAD_PresidentialPardonForm" << RESET " => ";
	try
	{
		*assignment = *presidential;
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BGRN "OK" << RESET "!";
		++const_oks;
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": " << BRED "KO" << RESET "!";
	}
	delete assignment;
	delete presidential;
	_separator(false);
}

void _test_ShrubberyCreationForm(void)
{
	// TEST_DEFAULT_CONSTRUCTOR_ShrubberyCreationForm
	_default_ShrubberyCreationForm();
	// TEST_DEFAULT_CONSTRUCTOR_2_ShrubberyCreationForm
	_test_default_ShrubberyCreationForm("shruberry_test");
	// TEST_COPY_CONSTRUCTOR_ShrubberyCreationForm
	_test_copy_ShrubberyCreationForm();
	// TEST_ASSIGNMENT_OVERLOAD_ShrubberyCreationForm
	_test_assignment_ShrubberyCreationForm();
}

void _test_RobotomyRequestForm(void)
{
	// TEST_DEFAULT_CONSTRUCTOR_RobotomyRequestForm
	_default_RobotomyRequestForm();
	// TEST_DEFAULT_CONSTRUCTOR_2_RobotomyRequestForm
	_test_default_RobotomyRequestForm("robotomy_test");
	// TEST_COPY_CONSTRUCTOR_RobotomyRequestForm
	_test_copy_RobotomyRequestForm();
	// TEST_ASSIGNMENT_OVERLOAD_RobotomyRequestForm
	_test_assignment_RobotomyRequestForm();
}

void _test_PresidentialPardonForm(void)
{
	// TEST_DEFAULT_CONSTRUCTOR_PresidentialPardonForm
	_default_PresidentialPardonForm();
	// TEST_DEFAULT_CONSTRUCTOR_2_PresidentialPardonForm
	_test_default_PresidentialPardonForm("presidential_test");
	// TEST_COPY_CONSTRUCTOR_PresidentialPardonForm
	_test_copy_PresidentialPardonForm();
	// TEST_ASSIGNMENT_OVERLOAD_PresidentialPardonForm
	_test_assignment_PresidentialPardonForm();
}

void _test_exec_ShrubberyCreationForm(bool result_bc, bool result_sign, bool result_exec, int grade)
{
	++tests_try;
	_separator(true);
	std::stringstream test_name;
	test_name << "test" << ++i;
	AForm* shrubbery = new ShrubberyCreationForm(test_name.str());
	std::cout << BCYN "TEST_EXECUTION_ShrubberyCreationForm->";
	std::cout << test_name.str() << "->create" << RESET " => ";
	try
	{
		Bureaucrat bc(test_name.str(), grade);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": ";
		if (result_bc)
		{
			std::cout << BGRN "OK" << RESET "!" << std::endl << std::endl;
			std::cout << BCYN "TEST_EXECUTION_ShrubberyCreationForm->";
			std::cout << test_name.str() << "->sign" << RESET " => ";
			try
			{
				shrubbery->beSigned(bc);
				std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
				std::cout << BCYN "Result" << RESET ": ";
				if (result_sign)
				{
					std::cout << BGRN "OK" << RESET "!" << std::endl << std::endl;
					std::cout << BCYN "TEST_EXECUTION_ShrubberyCreationForm->";
					std::cout << test_name.str() << "->execute" << RESET " => ";
					try
					{
						shrubbery->execute(bc);
						std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
						std::cout << BCYN "Result" << RESET ": ";
						if (result_exec)
						{
							std::ifstream tmp;
							tmp.open((test_name.str() + "_shrubbery").c_str());
							if (tmp)
							{
								std::cout << BGRN "OK" << RESET "!";
								++tests_oks;
							}
							else
								std::cout << BRED "KO" << RESET "!";
						}
						else
							std::cout << BRED "KO" << RESET "!";
					}
					catch(std::exception& e)
					{
						std::cout << RED "Error! " << e.what() << std::endl << std::endl;
						std::cout << BCYN "Result" << RESET ": ";
						if (result_exec)
							std::cout << BRED "KO";
						else
						{
							std::cout << BGRN "OK";
							++tests_oks;
						}
						std::cout << RESET "!";
					}
				}
				else
					std::cout << BRED "KO" << RESET "!";
			}
			catch(std::exception& e)
			{
				std::cout << RED "Error! " << e.what() << std::endl << std::endl;
				std::cout << BCYN "Result" << RESET ": ";
				if (result_sign)
					std::cout << BRED "KO";
				else
				{
					std::cout << BGRN "OK";
					++tests_oks;
				}
				std::cout << RESET "!";
			}
		}
		else
			std::cout << BRED "KO" << RESET "!";
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": ";
		if (result_bc)
			std::cout << BRED "KO";
		else
		{
			std::cout << BGRN "OK";
			++tests_oks;
		}
		std::cout << RESET "!";
	}
	delete shrubbery;
	_separator(false);
}

void _test_exec_RobotomyRequestForm(bool result_bc, bool result_sign, bool result_exec, int grade)
{
	++tests_try;
	_separator(true);
	std::stringstream test_name;
	test_name << "test" << ++i;
	AForm* robotmy = new RobotomyRequestForm(test_name.str());
	std::cout << BCYN "TEST_EXECUTION_RobotomyRequestForm->";
	std::cout << test_name.str() << "->create" << RESET " => ";
	try
	{
		Bureaucrat bc(test_name.str(), grade);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" << RESET ": ";
		if (result_bc)
		{
			std::cout << BGRN "OK" << RESET "!" << std::endl << std::endl;
			std::cout << BCYN "TEST_EXECUTION_RobotomyRequestForm->";
			std::cout << test_name.str() << "->sign" << RESET " => ";
			try
			{
				robotmy->beSigned(bc);
				std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
				std::cout << BCYN "Result" << RESET ": ";
				if (result_sign)
				{
					std::cout << BGRN "OK" << RESET "!" << std::endl << std::endl;
					std::cout << BCYN "TEST_EXECUTION_RobotomyRequestForm->";
					std::cout << test_name.str() << "->execute" << RESET " => ";
					try
					{
						robotmy->execute(bc);
						std::cout << RESET " -> " << GRN "Success" << RESET "! " << std::endl << std::endl;
						std::cout << BCYN "Result" << RESET ": ";
						if (result_exec)
						{
							std::cout << BGRN "OK" << RESET "!";
							++tests_oks;
						}
						else
							std::cout << BRED "KO" << RESET "!";
					}
					catch(std::exception& e)
					{
						std::cout << RED "Error! " << e.what() << std::endl << std::endl;
						std::cout << BCYN "Result" RESET ": ";
						if (result_exec)
							std::cout << BRED "KO";
						else
						{
							std::cout << BGRN "OK";
							++tests_oks;
						}
						std::cout << RESET "!";
					}
				}
				else
					std::cout << BRED "KO" << RESET "!";
			}
			catch(std::exception& e)
			{
				std::cout << RED "Error! " << e.what() << std::endl << std::endl;
				std::cout << BCYN "Result" RESET ": ";
				if (result_sign)
					std::cout << BRED "KO";
				else
				{
					std::cout << BGRN "OK";
					++tests_oks;
				}
				std::cout << RESET "!";
			}
		}
		else
			std::cout << BRED "KO" << RESET "!";
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" RESET ": ";
		if (result_bc)
			std::cout << BRED "KO";
		else
		{
			std::cout << BGRN "OK";
			++tests_oks;
		}
		std::cout << RESET "!";
	}
	delete robotmy;
	_separator(false);
}

void _test_exec_PresidentialPardonForm(bool result_bc, bool result_sign, bool result_exec, int grade)
{
	++tests_try;
	_separator(true);
	std::stringstream test_name;
	test_name << "test" << ++i;
	AForm* presidential = new PresidentialPardonForm(test_name.str());
	std::cout << BCYN "TEST_EXECUTION_PresidentialPardonForm->";
	std::cout << test_name.str() << "->create" << RESET " => ";
	try
	{
		Bureaucrat bc(test_name.str(), grade);
		std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
		std::cout << BCYN "Result" RESET ": ";
		if (result_bc)
		{
			std::cout << BGRN "OK" RESET "!" << std::endl << std::endl;
			std::cout << BCYN "TEST_EXECUTION_PresidentialPardonForm->";
			std::cout << test_name.str() << "->sign" << RESET " => ";
			try
			{
				presidential->beSigned(bc);
				std::cout << GRN "Success" RESET "! " << std::endl << std::endl;
				std::cout << BCYN "Result" RESET ": ";
				if (result_sign)
				{
					std::cout << BGRN "OK" RESET "!" << std::endl << std::endl;
					std::cout << BCYN "TEST_EXECUTION_PresidentialPardonForm->";
					std::cout << test_name.str() << "->execute " RESET "=> ";
					try
					{
						presidential->execute(bc);
						std::cout << RESET " -> " << GRN "Success" << RESET "! " << std::endl << std::endl;
						std::cout << BCYN "Result" RESET ": ";
						if (result_exec)
						{
							std::cout << BGRN "OK" RESET "!";
							++tests_oks;
						}
						else
							std::cout << BRED "KO" RESET "!";
					}
					catch(std::exception& e)
					{
						std::cout << RED "Error! " << e.what() << std::endl << std::endl;
						std::cout << BCYN "Result" RESET ": ";
						if (result_exec)
							std::cout << BRED "KO";
						else
						{
							std::cout << BGRN "OK";
							++tests_oks;
						}
						std::cout << RESET "!";
					}
				}
				else
					std::cout << BRED "KO" RESET "!";
			}
			catch(std::exception& e)
			{
				std::cout << RED "Error! " << e.what() << std::endl << std::endl;
				std::cout << BCYN "Result" RESET ": ";
				if (result_sign)
					std::cout << BRED "KO";
				else
				{
					std::cout << BGRN "OK";
					++tests_oks;
				}
				std::cout << RESET "!";
			}
		}
		else
			std::cout << BRED "KO" RESET "!";
	}
	catch(std::exception& e)
	{
		std::cout << RED "Error! " << e.what() << std::endl << std::endl;
		std::cout << BCYN "Result" RESET ": ";
		if (result_bc)
			std::cout << BRED "KO";
		else
		{
			std::cout << BGRN "OK";
			++tests_oks;
		}
		std::cout << RESET "!";
	}
	delete presidential;
	_separator(false);
}

void _test_exec_mix(bool result_bc, \
	bool result_sign_shrubbery, bool result_exec_shrubbery, \
	bool result_sign_robotmy, bool result_exec_robotmy, \
	bool result_sign_presidential, bool result_exec_presidential, \
	int grade)
{
	_test_exec_ShrubberyCreationForm(result_bc, result_sign_shrubbery, result_exec_shrubbery, grade);
	_test_exec_RobotomyRequestForm(result_bc, result_sign_robotmy, result_exec_robotmy, grade);
	_test_exec_PresidentialPardonForm(result_bc, result_sign_presidential, result_exec_presidential, grade);
}

int	main(void)
{
	// TEST ShrubberyCreationForm
	_test_ShrubberyCreationForm();
	// TEST RobotomyRequestForm
	_test_RobotomyRequestForm();
	// TEST PresidentialPardonForm
	_test_PresidentialPardonForm();
	int sign, exec;
	// TEST_EXECUTION_ShrubberyCreationForm
	sign = 145;	// lowest possible sign grade: 145
	exec = 137;	// lowest possible sign grade: 137
	_test_exec_ShrubberyCreationForm(false, false, false, 0       );		// invalid grade | invalid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , true , true , 1       );		//   valid grade |   valid sign |   valid execute
	_test_exec_ShrubberyCreationForm(true , true , true , exec    );		//   valid grade |   valid sign |   valid execute
	_test_exec_ShrubberyCreationForm(true , true , false, exec + 1);		//   valid grade |   valid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , true , false, sign    );		//   valid grade |   valid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , false, false, sign + 1);		//   valid grade | invalid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , false, false, 150     );		//   valid grade | invalid sign | invalid execute
	_test_exec_ShrubberyCreationForm(false, false, false, 151     );		// invalid grade | invalid sign | invalid execute
	// TEST_EXECUTION_RobotomyRequestForm
	sign = 72;	// lowest possible sign grade: 72
	exec = 45;	// lowest possible sign grade: 45
	_test_exec_RobotomyRequestForm(false, false, false, 0       );			// invalid grade | invalid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , true , true , 1       );			//   valid grade |   valid sign |   valid execute
	_test_exec_RobotomyRequestForm(true , true , true , exec    );			//   valid grade |   valid sign |   valid execute
	_test_exec_RobotomyRequestForm(true , true , false, exec + 1);			//   valid grade |   valid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , true , false, sign    );			//   valid grade |   valid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , false, false, sign + 1);			//   valid grade | invalid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , false, false, 150     );			//   valid grade | invalid sign | invalid execute
	_test_exec_RobotomyRequestForm(false, false, false, 151     );			// invalid grade | invalid sign | invalid execute
	// TEST_EXECUTION_PresidentialPardonForm
	sign = 25;	// lowest possible sign grade: 25
	exec = 5;	// lowest possible sign grade: 5
	_test_exec_PresidentialPardonForm(false, false, false, 0       );		// invalid grade | invalid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , true , true , 1       );		//   valid grade |   valid sign |   valid execute
	_test_exec_PresidentialPardonForm(true , true , true , exec    );		//   valid grade |   valid sign |   valid execute
	_test_exec_PresidentialPardonForm(true , true , false, exec + 1);		//   valid grade |   valid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , true , false, sign    );		//   valid grade |   valid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , false, false, sign + 1);		//   valid grade | invalid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , false, false, 150     );		//   valid grade | invalid sign | invalid execute
	_test_exec_PresidentialPardonForm(false, false, false, 151     );		// invalid grade | invalid sign | invalid execute
	// TEST_EXECUTION_MIXES
	// BCC -> Bureaucrat creation grade
	// SHS -> Shrubbery sign grade
	// SHE -> Shrubbery execute grade
	// RBS -> Robotomy sign grade
	// RBE -> Robotomy execute grade
	// PRS -> Presidential sign grade
	// PRE -> Presidential execute grade
	// inv -> invalid | val -> valid										// BCC | SHS | SHE | RBS | RBE | PRS | PRE
	_test_exec_mix(false, false, false, false, false, false, false, 0  );	// inv | inv | inv | inv | inv | inv | inv
	_test_exec_mix(true , true , true , true , true , true , true , 1  );	// val | val | val | val | val | val | val
	_test_exec_mix(true , true , true , true , true , true , true , 5  );	// val | val | val | val | val | val | val
	_test_exec_mix(true , true , true , true , true , true , false, 6  );	// val | val | val | val | val | val | inv
	_test_exec_mix(true , true , true , true , true , true , false, 25 );	// val | val | val | val | val | val | inv
	_test_exec_mix(true , true , true , true , true , false, false, 26 );	// val | val | val | val | val | inv | inv
	_test_exec_mix(true , true , true , true , true , false, false, 45 );	// val | val | val | val | val | inv | inv
	_test_exec_mix(true , true , true , true , false, false, false, 46 );	// val | val | val | val | inv | inv | inv
	_test_exec_mix(true , true , true , true , false, false, false, 72 );	// val | val | val | val | inv | inv | inv
	_test_exec_mix(true , true , true , false, false, false, false, 73 );	// val | val | val | inv | inv | inv | inv
	_test_exec_mix(true , true , true , false, false, false, false, 137);	// val | val | val | inv | inv | inv | inv
	_test_exec_mix(true , true , false, false, false, false, false, 138);	// val | val | inv | inv | inv | inv | inv
	_test_exec_mix(true , true , false, false, false, false, false, 145);	// val | val | inv | inv | inv | inv | inv
	_test_exec_mix(true , false, false, false, false, false, false, 146);	// val | inv | inv | inv | inv | inv | inv
	_test_exec_mix(true , false, false, false, false, false, false, 150);	// val | inv | inv | inv | inv | inv | inv
	_test_exec_mix(false, false, false, false, false, false, false, 151);	// inv | inv | inv | inv | inv | inv | inv
	_separator(true);
	std::cout << BCYN "FINAL RESULTS " << std::endl;
	std::cout << std::endl << BCYN "Constructors" RESET ": ";
	if (const_oks == const_try)
		std::cout << BGRN "OK" RESET "!";
	else
		std::cout << BRED "KO" RESET "! (you missed " << const_try - const_oks << " tests of " << const_try << ")";
	std::cout << std::endl << BCYN "Tests       " RESET ": ";
	if (tests_oks == tests_try)
		std::cout << BGRN "OK" RESET "!";
	else
		std::cout << BRED "KO" RESET "! (you missed " << tests_try - tests_oks << " tests of " << tests_try << ")";
	std::cout << std::endl << std::endl;
	return (0);
}
