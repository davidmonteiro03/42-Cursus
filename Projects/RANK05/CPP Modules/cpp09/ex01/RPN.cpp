/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:08:42 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 17:52:18 by dcaetano         ###   ########.fr       */
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

void display(std::list<int> list)
{
	std::list<int>::iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << "element: " << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
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
			throw InvalidInputException();
		if (getcode(_substr) == 1)
		{
			_list.push_front(std::atoi(_substr.c_str()));
		}
		else if (getcode(_substr) == 2)
		{
			if (_list.size() < 2)
				throw InvalidInputException();
			std::list<int>::iterator it = _list.begin();
			int first = *it++;
			int second = *it;
			int result;
			// std::cout << first << " " << second << std::endl;
			// std::cout << _substr << std::endl;
			if (_substr == "+")
				result = second + first;
			else if (_substr == "-")
				result = second - first;
			else if (_substr == "*")
				result = second * first;
			else
				result = second / first;
			_list.pop_front();
			_list.pop_front();
			_list.push_front(result);
		}
		// display(_list);
	}
	if (_list.size() != 1)
		throw InvalidInputException();
	std::list<int>::iterator it = _list.begin();
	std::cout << *it << std::endl;
}

const char* RPN::InvalidInputException::what() const throw()
{
	return ("Error");
}
