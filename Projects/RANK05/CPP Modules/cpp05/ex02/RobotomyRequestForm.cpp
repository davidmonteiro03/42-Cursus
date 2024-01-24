/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:05:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 08:35:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : \
	AForm("default robotomy", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : \
	AForm("robotomy", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : \
	AForm(copy.getName(), copy.getSignGrade(), \
	copy.getExecGrade()), _target(copy.getTarget())
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
		_target = other.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!getStatus())
		throw AForm::UnsignedFormException();
	else if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else
	{
		std::cout << "Success!" << std::endl;
	}
}
