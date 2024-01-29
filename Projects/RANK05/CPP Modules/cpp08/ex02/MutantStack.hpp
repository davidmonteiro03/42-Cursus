/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 07:37:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 08:14:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		MutantStack() { std::stack<T>(); }
		MutantStack(const MutantStack& copy) : std::stack<T>(copy) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		virtual ~MutantStack() {}
		iterator begin() { return std::stack<T>::c.begin(); }
		iterator end() { return std::stack<T>::c.end(); }
		const_iterator begin() const { return std::stack<T>::c.begin(); }
		const_iterator end() const { return std::stack<T>::c.end(); }
		reverse_iterator rbegin() { return std::stack<T>::c.rbegin(); }
		reverse_iterator rend() { return std::stack<T>::c.rend(); }
		const_reverse_iterator rbegin() const { return std::stack<T>::c.rbegin(); }
		const_reverse_iterator rend() const { return std::stack<T>::c.rend(); }
};

#endif
