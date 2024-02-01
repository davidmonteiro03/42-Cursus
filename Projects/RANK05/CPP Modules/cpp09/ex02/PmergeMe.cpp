/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:08:49 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/01 14:15:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
	typename T::iterator _it = _data.begin();
	while (_it != _data.end())
	{
		if (*_it == num)
			return (false);
		++_it;
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
	_vector(std::vector<int>()), _copy(std::vector<int>())
{
	std::string input = join_args_to_str(argv);
	parse_input(input);
	fill_data(_vector, input);
	_copy = _vector;
}

PmergeMe::PmergeMe(const PmergeMe& copy) : \
	_vector(copy._vector), _copy(copy._copy) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_copy = other._copy;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void display_vector_pairs(std::vector<std::pair<int, int> > _vector_pairs)
{
	std::vector<std::pair<int, int> >::iterator _it = _vector_pairs.begin();
	while (_it != _vector_pairs.end())
	{
		if (_it != _vector_pairs.begin())
			std::cout << " ";
		std::cout << "[" << _it->first << ", " << _it->second << "]";
		_it++;
	}
	std::cout << std::endl;
}

void insert(std::pair<int, int> _element, \
	std::vector<std::pair<int, int> >& _pairs, int n)
{
	if (n < 0)
		_pairs.insert(_pairs.begin(), _element);
	else if (_element.first >= _pairs[n].first)
		_pairs.insert(_pairs.begin() + n + 1, _element);
	else
		insert(_element, _pairs, n - 1);
}

void sort_pairs(std::vector<std::pair<int, int> >& _pairs, int n)
{
	if (n < 1)
		return ;
	sort_pairs(_pairs, n - 1);
	std::pair<int, int> _element = _pairs[n];
	_pairs.erase(_pairs.begin() + n);
	insert(_element, _pairs, n - 1);
}

std::vector<int> prepare_vector(std::vector<std::pair<int, int> > _pairs)
{
	std::vector<int> _ret;
	std::vector<std::pair<int, int> >::iterator _it = _pairs.begin();
	while (_it != _pairs.end())
	{
		if (_it == _pairs.begin())
		{
			_ret.push_back(_it->second);
			_ret.push_back(_it->first);
		}
		else
			_ret.push_back(_it->first);
		_it++;
	}
	return (_ret);
}

std::vector<int> create_jacob(std::vector<std::pair<int, int> > _pairs)
{
	std::vector<int> _ret;
	int jacob_list[] = {
		1,  3,      5,      11,        43,  683, 2731,
		43691, 174763, 2796203, 715827883, 2147483647
	}, max_index_b = _pairs.size(), max_need_index = 0, i, cur;
	while (max_index_b > jacob_list[max_need_index])
		max_need_index++;
	if (max_need_index == 0)
		return (_ret);
	for (i = 0; i < max_need_index; i++)
	{
		cur = jacob_list[i + 1];
		if (max_index_b < cur)
			cur = max_index_b;
		while (cur > jacob_list[i])
			_ret.push_back(cur--);
	}
	return (_ret);
}

void display_vector(std::vector<int> _vector)
{
	std::vector<int>::iterator _it = _vector.begin();
	while (_it != _vector.end())
	{
		if (_it != _vector.begin())
			std::cout << " ";
		std::cout << *_it++;
	}
}

void merge_insert_sort_vector(std::vector<int>& _vector)
{
	if (_vector.size() < 2)
		return ;
	int special_element = 0;
	bool is_odd = _vector.size() % 2;
	if (is_odd)
	{
		special_element = _vector.back();
		_vector.pop_back();
	}
	std::vector<std::pair<int, int> > _pairs;
	std::vector<std::pair<int, int> >::iterator _pairs_it;
	std::vector<int>::iterator _it = _vector.begin(), _s_it;
	while (_it != _vector.end())
	{
		_pairs.push_back(std::pair<int, int>(*_it, *(_it + 1)));
		_it += 2;
	}
	_pairs_it = _pairs.begin();
	while (_pairs_it != _pairs.end())
	{
		if (_pairs_it->first < _pairs_it->second)
			std::swap(_pairs_it->first, _pairs_it->second);
		_pairs_it++;
	}
	sort_pairs(_pairs, _pairs.size() - 1);
	std::vector<int> _ret, _jacob_sequence = prepare_vector(_pairs);
	_ret = prepare_vector(_pairs);
	if (is_odd)
		_pairs.push_back(std::pair<int, int>(0, special_element));
	_jacob_sequence = create_jacob(_pairs);
	_it = _jacob_sequence.begin();
	while (_it != _jacob_sequence.end())
	{
		_s_it = _ret.begin();
		while (*_s_it < _pairs[*_it - 1].second)
			_s_it++;
		_ret.insert(_s_it, _pairs[*_it - 1].second);
		_it++;
	}
	_vector = _ret;
}

void PmergeMe::execute(void)
{
	if (_vector.size() <= 0)
		return ;
	merge_insert_sort_vector(_vector);
	display_vector(_vector);
	// std::cout << "Time to process a range of " << _copy.size() << std::endl;
}

const char* PmergeMe::ErrorException::what() const throw()
{
	return ("Error");
}
