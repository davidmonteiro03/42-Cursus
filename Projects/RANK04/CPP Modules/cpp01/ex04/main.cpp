/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 07:21:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/06 08:44:54 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace(char **argv, std::string s1)
{
	std::ofstream	file_out;
	int				pos;

	file_out.open((std::string(argv[1]) + ".replace").c_str());
	for (int i = 0; i < (int)s1.size(); i++)
	{
		pos = s1.find(argv[2], i);
		if (pos != -1 && pos == i)
		{
			file_out << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			file_out << s1[i];
	}
	file_out.close();
	return (0);
}

int	argv_count(char **argv)
{
	int	i = -1;

	while (argv[++i])
		if (!*argv[i])
			return (i);
	return (i);
}

int	main(int argc, char **argv)
{
	char			c;
	std::string		s1;
	std::ifstream	file_in;

	if (argc != 4 || argv_count(argv) != 4)
	{
		std::cout << "Wrong number of arguments." << std::endl;
		return (1);
	}
	file_in.open(argv[1]);
	if (file_in.fail())
	{
		std::cout << "Error opening file." << std::endl;
		return (1);
	}
	while (!file_in.eof() && file_in >> std::noskipws >> c)
		s1 += c;
	file_in.close();
	return (replace(argv, s1));
}
