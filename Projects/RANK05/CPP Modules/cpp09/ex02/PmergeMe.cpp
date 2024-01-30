/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:08:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 13:01:16 by dcaetano         ###   ########.fr       */
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

static int parse_input(std::string input)
{
	int i = 0, args = 0;
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
		args++;
	}
	return (args);
}

template<typename T>
static bool check_dups(T _data, int num)
{
	typename T::iterator it = _data.begin();
	while (it != _data.end())
	{
		if (*it == num)
			return (false);
		++it;
	}
	return (true);
}

template<typename T>
static void fill_data(T& _data, std::string input)
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
		if (!check_dups(_data, num))
			throw PmergeMe::ErrorException();
		_data.push_back(num);
	}
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv) : \
	_list(std::list<int>()), _deque(std::deque<int>())
{
	std::string input = join_args_to_str(argv);
	parse_input(input);
	fill_data(_list, input);
	fill_data(_deque, input);
	_copy = _list;
}

PmergeMe::PmergeMe(const PmergeMe& copy) : \
	_list(copy._list), _deque(copy._deque), _copy(copy._copy) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_list = other._list;
		_deque = other._deque;
		_copy = other._copy;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

/* template<typename T>
static bool is_sorted(T _data)
{
	typename T::iterator it = _data.begin();
	while (std::next(it != _data.end())
	{
		std::cout << "sghdfashg\n";
		++it;
	}
} */

template<typename T>
static void merge(T& _data, T& left, T& right)
{
	typename T::iterator left_it = left.begin();
	typename T::iterator right_it = right.begin();
	while (left_it != left.end() && right_it != right.end())
	{
		if (*left_it < *right_it)
			_data.push_back(*left_it++);
		else
			_data.push_back(*right_it++);
	}
	while (left_it != left.end())
		_data.push_back(*left_it++);
	while (right_it != right.end())
		_data.push_back(*right_it++);
}

template<typename T>
static void merge_insert_sort(T& _data)
{
	if (_data.size() < 2)
		return ;
	T left, right;
	typename T::iterator it = _data.begin();
	std::advance(it, _data.size() / 2);
	left.assign(_data.begin(), it);
	right.assign(it, _data.end());
	merge_insert_sort(left);
	merge_insert_sort(right);
	_data.clear();
	merge(_data, left, right);
}

static std::ostream& operator<<(std::ostream& o, std::list<int> _list)
{
	int size = int(_list.size()), i = 0;
	if (size <= 5)
	{
		std::list<int>::iterator it = _list.begin();
		while (it != _list.end())
		{
			if (i++ > 0)
				o << " ";
			o << *it++;
		}
	}
	else
	{
		std::list<int>::iterator it = _list.begin();
		while (it != _list.end() && i < 4)
		{
			if (i++ > 0)
				o << " ";
			o << *it++;
		}
		o << " [...]";
	}
	return (o);
}

void PmergeMe::execute(void)
{
	merge_insert_sort(_list);
	std::cout << "Before:  " << _copy << std::endl;
	std::cout << "After:   " << _list << std::endl;
	std::cout << "Time to process a range of " << _copy.size() << std::endl;
}

const char* PmergeMe::ErrorException::what() const throw()
{
	return ("Error");
}
