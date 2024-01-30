/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:50:56 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 20:33:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _length(0), _storage(0) {}

Span::Span(unsigned int N) : _length(N), _storage(std::vector<int>()) {}

Span::Span(const Span& copy) : _length(copy._length)
{
	_storage.clear();
	_storage = copy._storage;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_length = other._length;
		_storage = other._storage;
	}
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int value)
{
	if (_storage.size() == _length)
		throw VectorIsFullException();
	_storage.push_back(value);
}

void Span::addNumberRange(std::vector<int>::iterator begin, \
	std::vector<int>::iterator end)
{
	if (begin >= end)
		return ;
	std::vector<int>::iterator tmp;
	size_t size = _storage.size(), add_size = 0;
	tmp = begin;
	while (tmp++ != end)
		add_size++;
	tmp = begin;
	_storage.resize(size + add_size);
	while (tmp != end)
		_storage.push_back(*tmp++);
}

int Span::shortestSpan(void)
{
	if (_storage.size() <= 1)
		throw TooFewElementsException();
	std::sort(_storage.begin(), _storage.end());
	int min = _storage[1] - _storage[0];
	for (unsigned int i = 0; i < _length - 1; i++)
		if (_storage[i + 1] - _storage[i] < min)
			min = _storage[i + 1] - _storage[i];
	return (min);
}

int Span::longestSpan(void) const
{
	if (_storage.size() <= 1)
		throw TooFewElementsException();
	std::vector<int>::const_iterator min, max;
	min = std::min_element(_storage.begin(), _storage.end());
	max = std::max_element(_storage.begin(), _storage.end());
	return (*max - *min);
}

const char* Span::VectorIsFullException::what() const throw()
{
	return ("Span: VectorIsFullException");
}

const char* Span::TooFewElementsException::what() const throw()
{
	return ("Span: TooFewElementsException");
}
