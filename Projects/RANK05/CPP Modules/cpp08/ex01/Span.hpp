/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:43:16 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 08:17:25 by dcaetano         ###   ########.fr       */
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
		int shortestSpan(void) const;
		int longestSpan(void) const;
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
