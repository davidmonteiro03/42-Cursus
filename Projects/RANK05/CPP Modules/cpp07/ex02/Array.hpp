/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 12:38:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 14:05:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
	private:
		unsigned int _size;
		T* _array;
	public:
		Array() : _size(0) { _array = new T[_size]; }
		Array(unsigned int n) : _size(n) { _array = new T[_size]; }
		Array(const Array& copy)
		{
			_array = NULL;
			*this = copy;
		}
		Array& operator=(const Array& other)
		{
			if (_array)
				delete [] _array;
			if (other.size() != 0)
			{
				_size = other.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return (*this);
		}
		~Array()
		{
			if (_array)
				delete [] _array;
		}
		T& operator[](unsigned int index)
		{
			if (index >= _size || !_array)
				throw InvalidIndexException();
			return (_array[index]);
		}
		unsigned int size(void) const { return _size; }
		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

template<typename T>
const char* Array<T>::InvalidIndexException::what() const throw()
{
	return ("Array<T>: InvalidIndexException");
}

#endif
