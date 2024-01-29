/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:40:13 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/29 17:21:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stdexcept>
# include <list>
# include <cstdlib>

class RPN
{
	private:
		std::list<int> _list;
	public:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		~RPN();
		void execute(std::string input);
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
