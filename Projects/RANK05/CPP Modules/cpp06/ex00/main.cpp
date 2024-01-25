/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:41:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/25 21:44:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool isChar(std::string arg)
{
	if (arg.length() == 1 && !isdigit(arg[0]))
		return (true);
	return (false);
}

bool isInt(std::string arg)
{
	int digit_count = 0;
	int i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!isdigit(arg[i]))
			return (false);
		if (isdigit(arg[i]))
			digit_count++;
		i++;
	}
	if (digit_count == 0)
		return (false);
	return (true);
}

bool isFloat(std::string arg)
{
	int dot_pos = -1, dot_count = 0;
	int f_pos = -1, f_count = 0;
	int digit_count = 0;
	int i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			dot_pos = i++;
			dot_count++;
			continue ;
		}
		if (arg[i] == 'f')
		{
			f_pos = i++;
			f_count++;
			continue ;
		}
		if (!isdigit(arg[i]) && arg[i] != '.' && arg[i] != 'f')
			return (false);
		if (isdigit(arg[i]))
			digit_count++;
		i++;
	}
	if (digit_count == 0)
		return (false);
	if (dot_count != 1 || f_count != 1)
		return (false);
	if (f_pos != int(arg.length()) - 1)
		return (false);
	if (dot_pos > f_pos)
		return (false);
	return (true);
}

bool isDouble(std::string arg)
{
	int dot_pos = -1, dot_count = 0;
	int f_pos = -1, f_count = 0;
	int digit_count = 0;
	int i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] == '.')
		{
			dot_pos = i++;
			dot_count++;
			continue ;
		}
		if (arg[i] == 'f')
		{
			f_pos = i++;
			f_count++;
			continue ;
		}
		if (!isdigit(arg[i]) && arg[i] != '.' && arg[i] != 'f')
			return (false);
		if (isdigit(arg[i]))
			digit_count++;
		i++;
	}
	if (digit_count == 0)
		return (false);
	if (f_count != 0)
		return (false);
	if (dot_count != 1)
		return (false);
	return (true);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (!*argv[1])
		return (1);
	std::string arg = argv[1];
	std::cout << "char: " << isChar(arg) << std::endl;
	std::cout << "int: " << isInt(arg) << std::endl;
	std::cout << "float: " << isFloat(arg) << std::endl;
	std::cout << "double: " << isDouble(arg) << std::endl;
	return (0);
}
