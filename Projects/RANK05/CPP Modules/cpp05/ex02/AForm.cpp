/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:49:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/25 08:45:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

static void checkGrade(const int grade)
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (grade < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm() : _name("form"), _status(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : \
	_name(name), _status(false), _signGrade(signGrade), _execGrade(execGrade)
{
	checkGrade(_signGrade);
	checkGrade(_execGrade);
}

AForm::AForm(const AForm& copy) : \
	_name(copy._name), _status(false), \
	_signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		;
	return (*this);
}

AForm::~AForm()
{
}

const std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getStatus(void) const
{
	return (_status);
}

int AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int AForm::getExecGrade(void) const
{
	return (_execGrade);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: GradeTooLowException");
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return ("AForm: AlreadySignedException");
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return ("AForm: UnsignedFormException");
}

void AForm::beSigned(Bureaucrat& bc)
{
	if (_status)
		throw AlreadySignedException();
	if (bc.getGrade() > _signGrade)
		throw GradeTooLowException();
	_status = true;
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
{
	o << form.getName();
	o << ", form sign grade ";
	o << form.getSignGrade();
	o << ", form execute grade ";
	o << form.getExecGrade();
	return (o);
}
