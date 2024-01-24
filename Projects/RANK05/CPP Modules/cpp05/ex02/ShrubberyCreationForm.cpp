/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:05:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 09:09:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : \
	AForm("default shrubbery", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : \
	AForm("shrubbery", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : \
	AForm(copy.getName(), copy.getSignGrade(), \
	copy.getExecGrade()), _target(copy.getTarget())
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		_target = other.getTarget();
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getStatus())
		throw AForm::UnsignedFormException();
	else if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::ofstream file_out;
		int rows = 4, columns = 5;
		const char* tree[] = {
			"   OOOOOOOO   ",
			" OOOOOOOOOOOO ",
			"OOOOOOOOOOOOOO",
			"OOOOOOOOOOOOOO",
			" OOOOOOOOOOOO ",
			"  OOOOOOOOOO  ",
			"      OO      ",
			"      OO      ",
			"      OO      ",
			NULL
		};
		file_out.open((_target + "_shrubbery").c_str());
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; tree[j]; j++)
			{
				file_out << tree[j];
				for (int k = 0; k < columns - 1; k++)
					file_out << " " << tree[j];
				file_out << "\n";
			}
			if (i < rows - 1)
				file_out << "\n";
		}
	}
}
