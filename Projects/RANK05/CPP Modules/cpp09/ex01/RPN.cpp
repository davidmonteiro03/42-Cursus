/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:08:42 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 15:59:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _list(std::list<int>()){}

RPN::RPN(const RPN& copy) : _list(std::list<int>(copy._list)){}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_list = other._list;
	return (*this);
}

RPN::~RPN() {}

static int getcode(std::string arg)
{
	// 0 for error
	// 1 for number
	// 2 for operator
	if (arg.size() == 0)
		return (0);
	if (arg.size() == 1 && \
		(arg[0] == '+' || arg[0] == '-' || \
		arg[0] == '*' || arg[0] == '/'))
		return (2);
	int i = 0;
	while (arg[i])
	{
		if (!isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void RPN::parseInput(std::string input) const
{
	int i = 0, numbers = 0, operators = 0, args = 0;
	int first = -1, last = -1;
	while (input[i])
	{
		while (input[i] && input[i] == ' ')
			i++;
		int start = i;
		while (input[i] && input[i] != ' ')
			i++;
		int end = i;
		std::string _substr = input.substr(start, end - start);
		if (!getcode(_substr))
			throw InvalidInputException();
		if (getcode(_substr) == 1)
		{
			numbers++;
			if (first == -1)
				first = args;
		}
		else if (getcode(_substr) == 2)
		{
			operators++;
			last = args;
		}
		args++;
	}
	if (operators != numbers - 1)
		throw InvalidInputException();
	if (first != 0 || last != args - 1)
		throw InvalidInputException();
}

const char* RPN::InvalidInputException::what() const throw()
{
	return ("RPN: InvalidInputException");
}
