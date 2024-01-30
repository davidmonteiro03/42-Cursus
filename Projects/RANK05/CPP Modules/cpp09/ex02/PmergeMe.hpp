/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/30 08:40:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <list>
# include <deque>
# include <stdexcept>
# include <cstdlib>

class PmergeMe
{
	private:
		PmergeMe();
		std::list<int> _list;
		std::deque<int> _deque;
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		class ErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
