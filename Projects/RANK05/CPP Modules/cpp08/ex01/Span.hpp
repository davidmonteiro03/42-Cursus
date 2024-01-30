/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:43:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 19:24:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <stdexcept>

class Span
{
	private:
		unsigned int _length;
		std::vector<int> _storage;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		Span& operator=(const Span& other);
		virtual ~Span();
		void addNumber(int value);
		int shortestSpan(void);
		int longestSpan(void) const;
		void addNumberRange(std::vector<int>::iterator begin, \
			std::vector<int>::iterator end);
		class VectorIsFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class TooFewElementsException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
