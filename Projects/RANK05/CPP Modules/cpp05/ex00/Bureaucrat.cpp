/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:41:37 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/22 18:43:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : \
	_name("hello"), _grade(10)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : \
	_name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : \
	_name(copy._name), _grade(copy._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: GradeTooLowException");
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bc)
{
	o << bc.getName();
	o << ", bureaucrat grade ";
	o << bc.getGrade();
	o << ".";
	return (o);
}
