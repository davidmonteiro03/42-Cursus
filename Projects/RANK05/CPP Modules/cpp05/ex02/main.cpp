/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:35:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 13:25:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

void _default_ShrubberyCreationForm(void)
{
	_separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_ShrubberyCreationForm->shrubbery => ";
		AForm* shrubbery = new ShrubberyCreationForm();
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
		delete shrubbery;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_default_ShrubberyCreationForm(std::string target)
{
	_separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_ShrubberyCreationForm->";
		std::cout << target << " => ";
		AForm* shrubbery = new ShrubberyCreationForm(target);
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
		delete shrubbery;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_copy_ShrubberyCreationForm(void)
{
	AForm* shrubbery = new ShrubberyCreationForm();
	_separator(true);
	std::cout << "TEST_COPY_CONSTRUCTOR_ShrubberyCreationForm => ";
	try
	{
		AForm* test(shrubbery);
		std::cout << "Success! " << std::endl << std::endl;
		if (test->getName() != shrubbery->getName() || \
			test->getStatus() != shrubbery->getStatus() || \
			test->getSignGrade() != shrubbery->getSignGrade() || \
			test->getExecGrade() != shrubbery->getExecGrade())
			std::cout << "Result: KO!";
		else
			std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	delete shrubbery;
	_separator(false);
}

void _test_assignment_ShrubberyCreationForm(void)
{
	AForm* shrubbery = new ShrubberyCreationForm();
	_separator(true);
	AForm* assignment = new ShrubberyCreationForm("assignment");
	std::cout << "TEST_ASSIGNMENT_OVERLOAD_ShrubberyCreationForm => ";
	try
	{
		*assignment = *shrubbery;
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	delete assignment;
	delete shrubbery;
	_separator(false);
}

void _default_RobotomyRequestForm(void)
{
	_separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_RobotomyRequestForm->shrubbery => ";
		AForm* robotmy = new RobotomyRequestForm();
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
		delete robotmy;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_default_RobotomyRequestForm(std::string target)
{
	_separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_RobotomyRequestForm->";
		std::cout << target << " => ";
		AForm* robotmy = new RobotomyRequestForm(target);
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
		delete robotmy;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_copy_RobotomyRequestForm(void)
{
	AForm* robotmy = new RobotomyRequestForm();
	_separator(true);
	std::cout << "TEST_COPY_CONSTRUCTOR_RobotomyRequestForm => ";
	try
	{
		AForm* test(robotmy);
		std::cout << "Success! " << std::endl << std::endl;
		if (test->getName() != robotmy->getName() || \
			test->getStatus() != robotmy->getStatus() || \
			test->getSignGrade() != robotmy->getSignGrade() || \
			test->getExecGrade() != robotmy->getExecGrade())
			std::cout << "Result: KO!";
		else
			std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	delete robotmy;
	_separator(false);
}

void _test_assignment_RobotomyRequestForm(void)
{
	AForm* robotmy = new RobotomyRequestForm();
	_separator(true);
	AForm* assignment = new RobotomyRequestForm("assignment");
	std::cout << "TEST_ASSIGNMENT_OVERLOAD_RobotomyRequestForm => ";
	try
	{
		*assignment = *robotmy;
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	delete assignment;
	delete robotmy;
	_separator(false);
}

void _default_PresidentialPardonForm(void)
{
	_separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_PresidentialPardonForm->shrubbery => ";
		AForm* presidential = new PresidentialPardonForm();
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
		delete presidential;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_default_PresidentialPardonForm(std::string target)
{
	_separator(true);
	try
	{
		std::cout << "TEST_DEFAULT_CONSTRUCTOR->";
		std::cout << "_default_PresidentialPardonForm->";
		std::cout << target << " => ";
		AForm* presidential = new PresidentialPardonForm(target);
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
		delete presidential;
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	_separator(false);
}

void _test_copy_PresidentialPardonForm(void)
{
	AForm* presidential = new PresidentialPardonForm();
	_separator(true);
	std::cout << "TEST_COPY_CONSTRUCTOR_PresidentialPardonForm => ";
	try
	{
		AForm* test(presidential);
		std::cout << "Success! " << std::endl << std::endl;
		if (test->getName() != presidential->getName() || \
			test->getStatus() != presidential->getStatus() || \
			test->getSignGrade() != presidential->getSignGrade() || \
			test->getExecGrade() != presidential->getExecGrade())
			std::cout << "Result: KO!";
		else
			std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
	}
	delete presidential;
	_separator(false);
}

void _test_assignment_PresidentialPardonForm(void)
{
	AForm* presidential = new PresidentialPardonForm();
	_separator(true);
	AForm* assignment = new PresidentialPardonForm("assignment");
	std::cout << "TEST_ASSIGNMENT_OVERLOAD_PresidentialPardonForm => ";
	try
	{
		*assignment = *presidential;
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: OK!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: KO!";
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
	_separator(true);
	static int i = 0;
	std::stringstream test_name;
	test_name << "test" << ++i;
	AForm* shrubbery = new ShrubberyCreationForm(test_name.str());
	std::cout << "TEST_EXECUTION_ShrubberyCreationForm->";
	std::cout << test_name.str() << "->create" << " => ";
	try
	{
		Bureaucrat bc(test_name.str(), grade);
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: ";
		if (result_bc)
		{
			std::cout << "OK!" << std::endl << std::endl;
			std::cout << "TEST_EXECUTION_ShrubberyCreationForm->";
			std::cout << test_name.str() << "->sign" << " => ";
			try
			{
				shrubbery->beSigned(bc);
				std::cout << "Success! " << std::endl << std::endl;
				std::cout << "Result: ";
				if (result_sign)
				{
					std::cout << "OK!" << std::endl << std::endl;
					std::cout << "TEST_EXECUTION_ShrubberyCreationForm->";
					std::cout << test_name.str() << "->execute => ";
					try
					{
						shrubbery->execute(bc);
						std::cout << "Success! " << std::endl << std::endl;
						std::cout << "Result: ";
						if (result_exec)
						{
							std::ifstream tmp;
							tmp.open((test_name.str() + "_shrubbery").c_str());
							if (tmp)
								std::cout << "OK!";
							else
								std::cout << "KO!";
						}
						else
							std::cout << "KO!";
					}
					catch(std::exception& e)
					{
						std::cout << "Error! " << e.what() << std::endl << std::endl;
						std::cout << "Result: ";
						if (result_exec)
							std::cout << "KO";
						else
							std::cout << "OK";
						std::cout << "!";
					}
				}
				else
					std::cout << "KO!";
			}
			catch(std::exception& e)
			{
				std::cout << "Error! " << e.what() << std::endl << std::endl;
				std::cout << "Result: ";
				if (result_sign)
					std::cout << "KO";
				else
					std::cout << "OK";
				std::cout << "!";
			}
		}
		else
			std::cout << "KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: ";
		if (result_bc)
			std::cout << "KO";
		else
			std::cout << "OK";
		std::cout << "!";
	}
	delete shrubbery;
	_separator(false);
}

void _test_exec_RobotomyRequestForm(bool result_bc, bool result_sign, bool result_exec, int grade)
{
	_separator(true);
	static int i = 0;
	std::stringstream test_name;
	test_name << "test" << ++i;
	AForm* robotmy = new RobotomyRequestForm(test_name.str());
	std::cout << "TEST_EXECUTION_RobotomyRequestForm->";
	std::cout << test_name.str() << "->create" << " => ";
	try
	{
		Bureaucrat bc(test_name.str(), grade);
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: ";
		if (result_bc)
		{
			std::cout << "OK!" << std::endl << std::endl;
			std::cout << "TEST_EXECUTION_RobotomyRequestForm->";
			std::cout << test_name.str() << "->sign" << " => ";
			try
			{
				robotmy->beSigned(bc);
				std::cout << "Success! " << std::endl << std::endl;
				std::cout << "Result: ";
				if (result_sign)
				{
					std::cout << "OK!" << std::endl << std::endl;
					std::cout << "TEST_EXECUTION_RobotomyRequestForm->";
					std::cout << test_name.str() << "->execute => ";
					try
					{
						robotmy->execute(bc);
						std::cout << " -> Success!" << std::endl << std::endl;
						std::cout << "Result: ";
						if (result_exec)
							std::cout << "OK!";
						else
							std::cout << "KO!";
					}
					catch(std::exception& e)
					{
						std::cout << "Error! " << e.what() << std::endl << std::endl;
						std::cout << "Result: ";
						if (result_exec)
							std::cout << "KO";
						else
							std::cout << "OK";
						std::cout << "!";
					}
				}
				else
					std::cout << "KO!";
			}
			catch(std::exception& e)
			{
				std::cout << "Error! " << e.what() << std::endl << std::endl;
				std::cout << "Result: ";
				if (result_sign)
					std::cout << "KO";
				else
					std::cout << "OK";
				std::cout << "!";
			}
		}
		else
			std::cout << "KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: ";
		if (result_bc)
			std::cout << "KO";
		else
			std::cout << "OK";
		std::cout << "!";
	}
	delete robotmy;
	_separator(false);
}

void _test_exec_PresidentialPardonForm(bool result_bc, bool result_sign, bool result_exec, int grade)
{
	_separator(true);
	static int i = 0;
	std::stringstream test_name;
	test_name << "test" << ++i;
	AForm* presidential = new PresidentialPardonForm(test_name.str());
	std::cout << "TEST_EXECUTION_PresidentialPardonForm->";
	std::cout << test_name.str() << "->create" << " => ";
	try
	{
		Bureaucrat bc(test_name.str(), grade);
		std::cout << "Success! " << std::endl << std::endl;
		std::cout << "Result: ";
		if (result_bc)
		{
			std::cout << "OK!" << std::endl << std::endl;
			std::cout << "TEST_EXECUTION_PresidentialPardonForm->";
			std::cout << test_name.str() << "->sign" << " => ";
			try
			{
				presidential->beSigned(bc);
				std::cout << "Success! " << std::endl << std::endl;
				std::cout << "Result: ";
				if (result_sign)
				{
					std::cout << "OK!" << std::endl << std::endl;
					std::cout << "TEST_EXECUTION_PresidentialPardonForm->";
					std::cout << test_name.str() << "->execute => ";
					try
					{
						presidential->execute(bc);
						std::cout << " -> Success!" << std::endl << std::endl;
						std::cout << "Result: ";
						if (result_exec)
							std::cout << "OK!";
						else
							std::cout << "KO!";
					}
					catch(std::exception& e)
					{
						std::cout << "Error! " << e.what() << std::endl << std::endl;
						std::cout << "Result: ";
						if (result_exec)
							std::cout << "KO";
						else
							std::cout << "OK";
						std::cout << "!";
					}
				}
				else
					std::cout << "KO!";
			}
			catch(std::exception& e)
			{
				std::cout << "Error! " << e.what() << std::endl << std::endl;
				std::cout << "Result: ";
				if (result_sign)
					std::cout << "KO";
				else
					std::cout << "OK";
				std::cout << "!";
			}
		}
		else
			std::cout << "KO!";
	}
	catch(std::exception& e)
	{
		std::cout << "Error! " << e.what() << std::endl << std::endl;
		std::cout << "Result: ";
		if (result_bc)
			std::cout << "KO";
		else
			std::cout << "OK";
		std::cout << "!";
	}
	delete presidential;
	_separator(false);
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
	_test_exec_ShrubberyCreationForm(false, false, false, 0       );	// invalid grade | invalid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , true , true , 1       );	//   valid grade |   valid sign |   valid execute
	_test_exec_ShrubberyCreationForm(true , true , true , exec    );	//   valid grade |   valid sign |   valid execute
	_test_exec_ShrubberyCreationForm(true , true , false, exec + 1);	//   valid grade |   valid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , true , false, sign    );	//   valid grade |   valid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , false, false, sign + 1);	//   valid grade | invalid sign | invalid execute
	_test_exec_ShrubberyCreationForm(true , false, false, 150     );	//   valid grade | invalid sign | invalid execute
	_test_exec_ShrubberyCreationForm(false, false, false, 151     );	// invalid grade | invalid sign | invalid execute
	// TEST_EXECUTION_RobotomyRequestForm
	sign = 72;	// lowest possible sign grade: 72
	exec = 45;	// lowest possible sign grade: 45
	_test_exec_RobotomyRequestForm(false, false, false, 0       );		// invalid grade | invalid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , true , true , 1       );		//   valid grade |   valid sign |   valid execute
	_test_exec_RobotomyRequestForm(true , true , true , exec    );		//   valid grade |   valid sign |   valid execute
	_test_exec_RobotomyRequestForm(true , true , false, exec + 1);		//   valid grade |   valid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , true , false, sign    );		//   valid grade |   valid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , false, false, sign + 1);		//   valid grade | invalid sign | invalid execute
	_test_exec_RobotomyRequestForm(true , false, false, 150     );		//   valid grade | invalid sign | invalid execute
	_test_exec_RobotomyRequestForm(false, false, false, 151     );		// invalid grade | invalid sign | invalid execute
	// TEST_EXECUTION_PresidentialPardonForm
	sign = 25;	// lowest possible sign grade: 25
	exec = 5;	// lowest possible sign grade: 5
	_test_exec_PresidentialPardonForm(false, false, false, 0       );	// invalid grade | invalid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , true , true , 1       );	//   valid grade |   valid sign |   valid execute
	_test_exec_PresidentialPardonForm(true , true , true , exec    );	//   valid grade |   valid sign |   valid execute
	_test_exec_PresidentialPardonForm(true , true , false, exec + 1);	//   valid grade |   valid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , true , false, sign    );	//   valid grade |   valid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , false, false, sign + 1);	//   valid grade | invalid sign | invalid execute
	_test_exec_PresidentialPardonForm(true , false, false, 150     );	//   valid grade | invalid sign | invalid execute
	_test_exec_PresidentialPardonForm(false, false, false, 151     );	// invalid grade | invalid sign | invalid execute
	// TEST_EXECUTION_MIXES
	// TODO...
	return (0);
}
