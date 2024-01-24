/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:05:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 11:23:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
	AForm("default presidential", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : \
	AForm("presidential", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : \
	AForm(copy.getName(), copy.getSignGrade(), \
	copy.getExecGrade()), _target(copy.getTarget())
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		_target = other.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getStatus())
		throw AForm::UnsignedFormException();
	else if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	else
		std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox";
}
