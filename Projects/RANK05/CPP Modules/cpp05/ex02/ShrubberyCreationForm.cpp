/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:05:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/25 08:30:35 by dcaetano         ###   ########.fr       */
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

void draw_tree(std::ofstream& file_out, const int execGrade, const int grade)
{
	int size = execGrade - grade + 4;
	int rows = execGrade - grade + 2, columns = execGrade - grade + 5;
	if (size <= 1 || rows <= 0 || columns <= 0)
		return ;
	if (rows > 14)
		rows = 14;
	if (columns > 19)
		columns = 19;
	if (size > 15)
	{
		size = 15;
		if (rows > 4)
			rows = 4;
		if (columns > 9)
			columns = 9;
	}
	for (int s = 0; s < rows; s++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int t = 0; t < columns; t++)
			{
				for (int j = 0; j < size - i - 1; j++)
					file_out << " ";
				for (int j = 0; j < 2 * i + 1; j++)
				{
					if (i == 0)
						file_out << "$";
					else if (j == 0)
						file_out << "/";
					else if (j == 2 * i)
						file_out << "\\";
					else if (i < size - 1)
						file_out << " ";
					else
						file_out << "_";
				}
				for (int j = 0; j < size - i - 1; j++)
					file_out << " ";
				if (t < columns - 1)
					file_out << "  ";
			}
			file_out << std::endl;
		}
		if (size > 1)
		{
			for (int k = 0; k < (size + 1) / 3; k++)
			{
				for (int t = 0; t < columns; t++)
				{
					for (int j = 0; j < size - size / 2; j++)
						file_out << " ";
					for (int j = size - size / 2; j < size + size / 2 - 1; j++)
					{
						if (j == size - size / 2 || j == size + size / 2 - 2)
							file_out << "|";
						else if (k == (size + 1) / 3 - 1)
							file_out << "_";
						else
							file_out << " ";
					}
					for (int j = 0; j < size - size / 2; j++)
						file_out << " ";
					if (t < columns - 1)
						file_out << "  ";
				}
				file_out << std::endl;
			}
		}
		if (s < rows - 1)
			file_out << std::endl;
	}
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
		file_out.open((_target + "_shrubbery").c_str());
		if (!file_out.is_open())
		{
			std::cout << "Couldn't open file" << std::endl;
			return ;
		}
		draw_tree(file_out, getExecGrade(), executor.getGrade());
	}
}
