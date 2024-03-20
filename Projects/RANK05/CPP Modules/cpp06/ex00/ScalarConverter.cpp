/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:55:28 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/20 07:56:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy){ *this = copy; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
		;
	return (*this);
}
ScalarConverter::~ScalarConverter() {}

void convertChar(char val)
{
	std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void convertInt(long int val)
{
	if (!(val >= std::numeric_limits<char>::min() && \
		val <= std::numeric_limits<char>::max()))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(val))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	if (!(val >= std::numeric_limits<int>::min() && \
		val <= std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void convertFloat(float val)
{
	if (!(val >= std::numeric_limits<char>::min() && \
		val <= std::numeric_limits<char>::max()))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(val))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	if (!(val >= std::numeric_limits<int>::min() && \
		val <= std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	if (val - static_cast<int>(val) == 0)
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	if (val - static_cast<int>(val) == 0)
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void convertDouble(double val)
{
	if (!(val >= std::numeric_limits<char>::min() && \
		val <= std::numeric_limits<char>::max()))
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(val))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
	if (!(val >= std::numeric_limits<int>::min() && \
		val <= std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(val) << std::endl;
	if (val - static_cast<int>(val) == 0)
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
	if (val - static_cast<int>(val) == 0)
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(val) << std::endl;
}

bool isInt(std::string arg)
{
	int i = -1, digit = 0;
	while (arg[++i])
	{
		if ((arg[i] == '+' || arg[i] == '-') && i != 0)
			return (false);
		if (!isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-')
			return (false);
		if (isdigit(arg[i]))
			digit++;
	}
	return (digit > 0);
}

bool isFloat(std::string arg)
{
	int i = -1, digit = 0, dot = 0, f = 0;
	while (arg[++i])
	{
		if ((arg[i] == '+' || arg[i] == '-') && i != 0)
			return (false);
		if (!isdigit(arg[i]) && \
			arg[i] != '+' && arg[i] != '-' && \
			arg[i] != '.' && arg[i] != 'f')
			return (false);
		if (isdigit(arg[i]))
			digit++;
		if (arg[i] == '.')
			dot++;
		if (arg[i] == 'f')
		{
			if (i != int(arg.length()) - 1)
				return (false);
			f++;
		}
	}
	return (digit > 0 && dot == 1 && f == 1);
}

bool isDouble(std::string arg)
{
	int i = -1, digit = 0, dot = 0, f = 0;
	while (arg[++i])
	{
		if ((arg[i] == '+' || arg[i] == '-') && i != 0)
			return (false);
		if (!isdigit(arg[i]) && \
			arg[i] != '+' && arg[i] != '-' && \
			arg[i] != '.' && arg[i] != 'f')
			return (false);
		if (isdigit(arg[i]))
			digit++;
		if (arg[i] == '.')
			dot++;
		if (arg[i] == 'f')
		{
			if (i != int(arg.length()) - 1)
				return (false);
			f++;
		}
	}
	return (digit > 0 && dot == 1 && f == 0);
}

void ScalarConverter::convert(std::string arg)
{
	if (arg.length() == 1 && !isdigit(arg[0]))
		convertChar(arg[0]);
	else if (arg == "-inff")
		convertFloat(-std::numeric_limits<float>::infinity());
	else if (arg == "+inff")
		convertFloat(std::numeric_limits<float>::infinity());
	else if (arg == "nanf")
		convertFloat(std::numeric_limits<float>::quiet_NaN());
	else if (arg == "-inf")
		convertDouble(-std::numeric_limits<double>::infinity());
	else if (arg == "+inf")
		convertDouble(std::numeric_limits<double>::infinity());
	else if (arg == "nan")
		convertDouble(std::numeric_limits<double>::quiet_NaN());
	else if (isInt(arg))
		convertInt(std::atol(arg.c_str()));
	else if (isFloat(arg))
		convertFloat(std::atof(arg.c_str()));
	else if (isDouble(arg))
		convertDouble(std::strtof(arg.c_str(), NULL));
	else
		std::cerr << "Impossible convertion" << std::endl;
}
