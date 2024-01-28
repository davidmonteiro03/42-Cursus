/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:50:56 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/28 19:52:16 by dcaetano         ###   ########.fr       */
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

int Span::shortestSpan(void) const
{
	if (_storage.size() <= 1)
		throw TooFewElementsException();
	std::vector<int> tmp = _storage;
	std::sort(tmp.begin(), tmp.end());
	std::cout << tmp[0] << std::endl;
	return (0);
}

int Span::longestSpan(void) const
{
	if (_storage.size() <= 1)
		throw TooFewElementsException();
	std::cout << _storage[0] << std::endl;
	return (0);
}

const char* Span::VectorIsFullException::what() const throw()
{
	return ("Span: VectorIsFullException");
}

const char* Span::TooFewElementsException::what() const throw()
{
	return ("Span: TooFewElementsException");
}
