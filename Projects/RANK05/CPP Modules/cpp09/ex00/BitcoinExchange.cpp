/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 08:39:04 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/31 08:48:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static std::vector<std::string> readfile(std::string filename)
{
	std::vector<std::string> ret;
	std::ifstream tmp;
	std::string buf;
	tmp.open(filename.c_str());
	if (tmp.fail())
		throw BitcoinExchange::ErrorOpeningFileException();
	if (tmp.is_open())
	{
		int i = 0;
		while (tmp)
		{
			std::getline(tmp, buf);
			if (i > 0)
				ret.push_back(buf);
			i++;
		}
		if (ret.size() > 1)
			ret.pop_back();
		tmp.close();
	}
	return (ret);
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) : \
	_filename(filename), _input(readfile(_filename)) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : \
	_filename(copy._filename), _input(copy._input) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_filename = other._filename;
		_input = other._input;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::getFilename(void) const \
	{ return (_filename); }

std::vector<std::string> BitcoinExchange::getInput(void) const \
	{ return (_input); }

static bool parse_date(std::string date)
{
	int i = 0;
	while (i < 10)
	{
		if ((i == 4 || i == 7) && date[i] != '-')
			return (false);
		if (!(i == 4 || i == 7) && !isdigit(date[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool check_month_day(int month, int day, int feb_days)
{
	int month_days[12] = {
		31, feb_days, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	}, i;
	for (i = 0; i < 12; i++)
		if (i == month - 1)
			break;
	return (i < 12 && day > 0 && day < month_days[i]);
}

static bool check_date(int year, int month, int day)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return (check_month_day(month, day, 29));
	return (check_month_day(month, day, 28));
}

static bool parse_exchange_str(std::string exchange_str)
{
	int i = 0, digit = 0, dot = 0;
	while (exchange_str[i])
	{
		if ((exchange_str[i] == '+' || exchange_str[i] == '-') && i != 0)
			return (false);
		if (exchange_str[i] == '.')
			dot++;
		if (isdigit(exchange_str[i]))
			digit++;
		i++;
	}
	return (digit > 0 && dot <= 1);
}

static int parse_line(std::string line)
{
	if (line.size() < 14)
		return (1);
	int i = 0;
	while (line[i] && isspace(line[i]))
		i++;
	int date_start = i;
	while (line[i] && !isspace(line[i]))
		i++;
	int date_end = i;
	std::string date = line.substr(date_start, date_end - date_start);
	if (!line[date_end - date_start] || date.size() != 10)
		return (1);
	if (!parse_date(date))
		return (1);
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (!check_date(year, month, day))
		return (1);
	while (line[i] && isspace(line[i]))
		i++;
	if (line[i] != '|')
		return (1);
	i++;
	while (line[i] && isspace(line[i]))
		i++;
	int exchange_start = i;
	while (line[i] && !isspace(line[i]))
		i++;
	int exchange_end = i;
	std::string exchange_str = \
		line.substr(exchange_start, exchange_end - exchange_start);
	if (!parse_exchange_str(exchange_str))
		return (1);
	while (line[i] && isspace(line[i]))
		i++;
	if (line[i])
		return (1);
	float exchange = std::atof(exchange_str.c_str());
	if (exchange < 0)
		return (2);
	if (exchange > 1000)
		return (3);
	return (0);
}

static t_data get_data(std::string line)
{
	t_data data;
	int i = 0;
	while (line[i] && isspace(line[i]))
		i++;
	int date_start = i;
	while (line[i] && !isspace(line[i]))
		i++;
	int date_end = i;
	data.date = line.substr(date_start, date_end - date_start);
	data.year = std::atoi(data.date.substr(0, 4).c_str());
	data.month = std::atoi(data.date.substr(5, 2).c_str());
	data.day = std::atoi(data.date.substr(8, 2).c_str());
	while (line[i] && isspace(line[i]))
		i++;
	i++;
	while (line[i] && isspace(line[i]))
		i++;
	int exchange_start = i;
	while (line[i] && !isspace(line[i]))
		i++;
	int exchange_end = i;
	std::string exchange_str = \
		line.substr(exchange_start, exchange_end - exchange_start);
	data.exchange = std::atof(exchange_str.c_str());
	return (data);
}

static bool check_empty(std::string line)
{
	int i = -1;
	while (line[++i])
		if (!isspace(line[i]))
			return (true);
	return (false);
}

static void display_error(std::string line, int code)
{
	if (code == 1)
	{
		if (check_empty(line))
			std::cout << "Error: bad input => " << line << std::endl;
		else
			std::cout << "Error: empty line." << std::endl;
	}
	else if (code == 2)
		std::cout << "Error: not a positive number." << std::endl;
	else if (code == 3)
		std::cout << "Error: too large a number." << std::endl;
	else if (code == 4)
		std::cout << "Error: empty file." << std::endl;
	else if (code == 5)
		std::cout << "Error: there is no dates before given one." << std::endl;
}

static void find_date(std::vector<std::string> database, std::string line)
{
	int check = parse_line(line), i;
	if (check)
		return (display_error(line, check));
	float min_ex;
	double	n1, n2, min;
	double	list[100] = {0, 31, 59.25, 90.25, 120.25, 151.25, \
						181.25, 212.25, 243.25, 273.25, 304.25, 334.25};
	t_data input = get_data(line);
	std::string oldest_date;
	for (i = 0; i < int(database.size()); i++)
	{
		t_data tmp;
		tmp.date = database[i].substr(0, 10);
		if (i == 0)
			oldest_date = tmp.date;
		else if (tmp.date < oldest_date)
			oldest_date = tmp.date;
	}
	if (input.date < oldest_date)
		return (display_error(line, 5));
	for (i = 0; i < int(database.size()); i++)
	{
		t_data tmp;
		tmp.date = database[i].substr(0, 10);
		tmp.year = std::atoi(tmp.date.substr(0, 4).c_str());
		tmp.month = std::atoi(tmp.date.substr(5, 2).c_str());
		tmp.day = std::atoi(tmp.date.substr(8, 2).c_str());
		std::string exchange_str = \
			database[i].substr(11, database[i].size() - 10);
		tmp.exchange = std::atof(exchange_str.c_str());
		n1 = 365.25 * (double)(tmp.year - 1901) + \
						(list[tmp.month - 1] + \
						(double)tmp.day);
		n2 = 365.25 * (double)(input.year - 1901) + \
						(list[input.month - 1] + \
						(double)input.day);
		double dif = std::abs(n2 - n1);
		if (i == 0)
		{
			min = dif;
			min_ex = tmp.exchange;
		}
		else if (dif < min && input.date >= tmp.date)
		{
			min = dif;
			min_ex = tmp.exchange;
		}
	}
	std::cout << input.date << " => ";
	std::cout << input.exchange  << " = ";
	std::cout << min_ex * input.exchange;
	std::cout << std::endl;
}

void BitcoinExchange::displayInputFile(bool parse) const
{
	if (_input.size() == 0)
		return (display_error("", 4));
	if (!parse)
		for (int i = 0; i < int(_input.size()); i++)
			std::cout << _input[i] << std::endl;
	else
	{
		std::vector<std::string> database = readfile("data.csv");
		for (int i = 0; i < int(_input.size()); i++)
			find_date(database, _input[i]);
	}
}

const char* BitcoinExchange::ErrorOpeningFileException::what() const throw()
{
	return ("Error: could not open file.");
}
