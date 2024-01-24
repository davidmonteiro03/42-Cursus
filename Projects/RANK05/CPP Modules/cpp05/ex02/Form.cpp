/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:49:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/24 17:18:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void checkGrade(const int grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
}

Form::Form() : _name("form"), _status(false), _signGrade(150), _execGrade(150)
{
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : \
	_name(name), _status(false), _signGrade(signGrade), _execGrade(execGrade)
{
	checkGrade(_signGrade);
	checkGrade(_execGrade);
}

Form::Form(const Form& copy) : \
	_name(copy._name), _status(false), \
	_signGrade(copy._signGrade), _execGrade(copy._execGrade)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		;
	return (*this);
}

Form::~Form()
{
	_status = false;
}

const std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getStatus(void) const
{
	return (_status);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecGrade(void) const
{
	return (_execGrade);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form: GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: GradeTooLowException");
}

const char* Form::AlreadySignedException::what() const throw()
{
	return ("Form: AlreadySignedException");
}

const char* Form::UnsignedFormException::what() const throw()
{
	return ("Form: UnsignedFormException");
}

void Form::beSigned(Bureaucrat& bc)
{
	if (_status)
		throw AlreadySignedException();
	if (bc.getGrade() > _signGrade)
		throw GradeTooLowException();
	_status = true;
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	o << form.getName();
	o << ", form sign grade ";
	o << form.getSignGrade();
	o << ", form execute grade ";
	o << form.getExecGrade();
	return (o);
}
