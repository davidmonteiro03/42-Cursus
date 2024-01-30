/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:08:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 08:49:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static std::string join_args_to_str(char **argv)
{
	std::stringstream ss;
	std::string buf;
	while (*argv)
		ss << *argv++ << " ";
	buf = ss.str();
	ss.str("");
	return (buf);
}

static bool check_arg(std::string arg)
{
	int i = -1, digit = 0;
	while (arg[++i])
	{
		if ((arg[i] == '+' || arg[i] == '-') && i != 0)
			return (false);
		if (!isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-')
			return (false);
		if (isdigit(arg[i]))
			digit++;
	}
	return (digit > 0);
}

static void parse_input(std::string input)
{
	int i = 0;
	while (input[i])
	{
		while (input[i] && isspace(input[i]))
			i++;
		int start = i;
		while (input[i] && !isspace(input[i]))
			i++;
		int end = i;
		std::string _substr = input.substr(start, end - start);
		if (!check_arg(_substr))
			throw PmergeMe::ErrorException();
		int num = std::atoi(_substr.c_str());
		if (num <= 0)
			throw PmergeMe::ErrorException();
		while (input[i] && isspace(input[i]))
			i++;
	}
}

static void fill_list(std::list<int>& _list, std::string input)
{
	int i = 0;
	while (input[i])
	{
		while (input[i] && isspace(input[i]))
			i++;
		int start = i;
		while (input[i] && !isspace(input[i]))
			i++;
		int end = i;
		std::string _substr = input.substr(start, end - start);
		int num = std::atoi(_substr.c_str());
		while (input[i] && isspace(input[i]))
			i++;
		_list.push_back(num);
	}
}

static void fill_deque(std::deque<int>& _deque, std::string input)
{
	int i = 0;
	while (input[i])
	{
		while (input[i] && isspace(input[i]))
			i++;
		int start = i;
		while (input[i] && !isspace(input[i]))
			i++;
		int end = i;
		std::string _substr = input.substr(start, end - start);
		int num = std::atoi(_substr.c_str());
		while (input[i] && isspace(input[i]))
			i++;
		_deque.push_back(num);
	}
}

/* static */ void display_list(std::list<int> _list)
{
	std::list<int>::iterator it = _list.begin();
	while (it != _list.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}

/* static */ void display_deque(std::deque<int> _deque)
{
	std::deque<int>::iterator it = _deque.begin();
	while (it != _deque.end())
	{
		std::cout << *it << std::endl;
		++it;
	}
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv) : \
	_list(std::list<int>()), _deque(std::deque<int>())
{
	std::string input = join_args_to_str(argv);
	parse_input(input);
	fill_list(_list, input);
	fill_deque(_deque, input);
	// display_list(_list);
	// display_deque(_deque);
}

PmergeMe::PmergeMe(const PmergeMe& copy) : \
	_list(copy._list), _deque(copy._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_list = other._list;
		_deque = other._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::ErrorException::what() const throw()
{
	return ("Error");
}
