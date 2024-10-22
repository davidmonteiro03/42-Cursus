/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:14:21 by dcaetano          #+#    #+#             */
/*   Updated: 2024/10/22 13:30:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#define COULD_NOT_OPEN_FILE "Error: could not open file."
#define INVALID_DATABASE_CSV "Error: invalid database csv."
#define INVALID_INPUT_FILE "Error: invalid input file."
#define DATE_IS_TOO_OLD "Error: date is too old."

typedef struct s_date
{
	unsigned int year, mounth, day;
} t_date;

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;
	void _readCSV(std::string);
	void _readInput(std::string);
	t_date _createDate(std::string, std::string, std::string);
	unsigned int _getNumDays(t_date);
	std::string _sDate(t_date);
	double _searchExchange(t_date);
	class CouldNotOpenFile : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class InvalidDatabaseCSV : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class InvalidInputFile : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class DateIsTooOld : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

public:
	BitcoinExchange(void);
	~BitcoinExchange();
	void _execute(std::string);
};

#endif // !BITCOINEXCHANGE_HPP
