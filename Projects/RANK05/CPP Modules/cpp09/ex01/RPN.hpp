/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:40:13 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 15:11:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stdexcept>
# include <list>

class RPN
{
	private:
		std::list<int> _list;
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN();
		void parseInput(std::string input) const;
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
