/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:00:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/01 14:09:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <stdexcept>
# include <cstdlib>
# include <ctime>
# include <cmath>
# include <ctime>

class PmergeMe
{
	private:
		PmergeMe();
		std::vector<int> _vector;
		std::deque<int> _deque;
		std::vector<int> _copy;
	public:
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		void execute(void);
		class ErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
