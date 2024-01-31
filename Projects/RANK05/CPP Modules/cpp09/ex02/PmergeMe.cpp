/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:08:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/31 18:50:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
void normal_display(T _data)
{
	typename T::iterator it = _data.begin();
	int i = 0;
	while (it != _data.end())
	{
		if (i++ > 0)
			std::cout << " ";
		std::cout << *it++;
	}
}

std::string join_args_to_str(char **argv)
{
	std::stringstream ss;
	std::string buf;
	while (*argv)
		ss << *argv++ << " ";
	buf = ss.str();
	ss.str("");
	return (buf);
}

bool check_arg(std::string arg)
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

int parse_input(std::string input)
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
		long int num = std::atol(_substr.c_str());
		if (num <= 0 || num > 2147483648)
			throw PmergeMe::ErrorException();
		while (input[i] && isspace(input[i]))
			i++;
		args++;
	}
	return (args);
}

template<typename T>
bool check_dups(T _data, int num)
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
void fill_data(T& _data, std::string input)
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
	_list(std::list<int>()), _copy(std::list<int>())
{
	std::string input = join_args_to_str(argv);
	parse_input(input);
	fill_data(_list, input);
	_copy = _list;
}

PmergeMe::PmergeMe(const PmergeMe& copy) : \
	_list(copy._list), _copy(copy._copy) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_list = other._list;
		_copy = other._copy;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void merge_insert_sort_list(std::list<int>& _list)
{
	size_t _size = _list.size();
	int num_jacob_elems = int(_size / 2) + _size % 2;
	std::list<int> _a, _b;
	std::list<int>::iterator _list_begin_it = _list.begin();
	std::list<int>::iterator _list_end_it = _list.end();
	if (_size % 2)
		_list_end_it--;
	while (_list_begin_it != _list_end_it)
	{
		int first = *_list_begin_it++;
		int second = *_list_begin_it++;
		if (first > second)
			std::swap(first, second);
		_a.push_back(second);
		_b.push_back(first);
	}
	if (_size % 2)
		_b.push_back(*_list_begin_it);
	_list.clear();
	std::list<int>::iterator _a_it = _a.begin();
	std::list<int>::iterator _b_it = _b.begin();
	while (_a_it != _a.end())
	{
		std::list<int>::iterator _a_tmp_it = ++_a_it;
		std::list<int>::iterator _b_tmp_it = ++_b_it;
		_a_it--;
		_b_it--;
		while (_a_tmp_it != _a.end())
		{
			if (*_a_it > *_a_tmp_it)
			{
				std::swap(*_a_it, *_a_tmp_it);
				std::swap(*_b_it, *_b_tmp_it);
			}
			_a_tmp_it++;
			_b_tmp_it++;
		}
		_a_it++;
		_b_it++;
	}
	_a.push_front(*(_b.begin()));
	_b.pop_front();
	int jacob_list[num_jacob_elems];
	for(int i = 0; i < num_jacob_elems; i++)
		jacob_list[i] = (std::pow(2, i) - std::pow(-1, i)) / 3;
	for(int i = 0; i < num_jacob_elems - 1; i++)
	{
		int dif = jacob_list[i + 1] - jacob_list[i];
		if (dif == 0)
			continue ;
		std::list<int>::iterator _iter_b = _b.begin();
		std::list<int>::iterator _before_bgn = _iter_b;
		int count = 0;
		_before_bgn--;
		std::advance(_iter_b, dif - 1);
		while (_iter_b != _before_bgn)
		{
			std::list<int>::iterator _iter_a = _a.begin();
			while (*_iter_b > *_iter_a)
				_iter_a++;
			_a.insert(_iter_a, *_iter_b);
			_iter_b--;
			count++;
		}
		for (int j = 0; j < count; j++)
			_b.pop_front();
	}
	if (_b.size() > 0)
	{
		std::list<int>::iterator _iter_a = _a.begin();
		int _elem = *(_b.begin());
		while (_elem > *_iter_a)
			_iter_a++;
		_a.insert(_iter_a, _elem);
		_b.pop_front();
	}
	_list = _a;
}

void PmergeMe::execute(void)
{
	if (_list.size() <= 0)
		return ;
	merge_insert_sort_list(_list);
	std::cout << "Before:  "; normal_display(_copy); std::cout << std::endl;
	std::cout << "After:   "; normal_display(_list); std::cout << std::endl;
	// std::cout << "Time to process a range of " << _copy.size() << std::endl;
}

const char* PmergeMe::ErrorException::what() const throw()
{
	return ("Error");
}
