/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:24:34 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/01 09:51:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <list>
# include <stdexcept>
# include <cstdlib>

typedef struct s_data
{
	std::string date;
	int year;
	int month;
	int day;
	float exchange;
}t_data;

class BitcoinExchange
{
	private:
		BitcoinExchange();
		std::string _filename;
		std::list<std::string> _input;
	public:
		BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		virtual ~BitcoinExchange();
		std::string getFilename(void) const;
		std::list<std::string> getInput(void) const;
		void displayInputFile(bool parse) const;
		class ErrorOpeningFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
