/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:08:42 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 07:09:57 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack(std::stack<double>()) {}

RPN::RPN(const RPN& copy) : _stack(std::stack<double>(copy._stack)) {}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
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

void RPN::execute(std::string input)
{
	int i = 0;
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
			throw ErrorException();
		if (getcode(_substr) == 1)
			_stack.push(std::atoi(_substr.c_str()));
		else if (getcode(_substr) == 2)
		{
			if (_stack.size() < 2)
				throw ErrorException();
			double first = _stack.top();
			_stack.pop();
			double second = _stack.top();
			_stack.pop();
			double result;
			if (_substr == "+")
				result = second + first;
			else if (_substr == "-")
				result = second - first;
			else if (_substr == "*")
				result = second * first;
			else
			{
				if (first == 0)
					throw ErrorException();
				result = second / first;
			}
			_stack.push(result);
		}
	}
	if (_stack.size() != 1)
		throw ErrorException();
	std::cout << _stack.top() << std::endl;
}

const char* RPN::ErrorException::what() const throw()
{
	return ("Error");
}
