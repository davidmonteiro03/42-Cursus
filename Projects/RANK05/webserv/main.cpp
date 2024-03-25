/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:15:51 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/25 19:46:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::string> readfile(std::string filename)
{
	std::vector<std::string> ret;
	std::ifstream tmp;
	std::string buf;
	tmp.open(filename.c_str());
	if (tmp.fail())
		return (std::vector<std::string>());
	if (tmp.is_open())
	{
		int i = 0;
		while (tmp)
		{
			std::getline(tmp, buf);
			ret.push_back(buf);
			i++;
		}
		ret.pop_back();
		tmp.close();
	}
	return ret;
}

bool justwhtspc(std::string str)
{
	size_t i = 0;
	while (str[i])
	{
		if (!isspace(str[i]))
			return false;
		++i;
	}
	return true;
}

void remove_comments(std::string& str)
{
	std::string::iterator it = str.begin();
	while (it != str.end())
	{
		if (*it == ';' || *it == '#')
			break ;
		++it;
	}
	if (*it == ';')
		++it;
	while (it != str.end())
		it = str.erase(it);
}

void trim_end_line(std::string& str)
{
	size_t i;
	for (i = 0; i < str.size(); i++)
		if (!isspace(str[str.size() - i - 1]))
			break ;
	for (size_t j = 0; j < i; j++)
		str.erase(str.size() - 1);
}

int main(int argc, char **argv)
{
	if (argc != 2 || (argc == 2 && !*argv[1]))
	{
		std::cout << "usage: ./webserv [config]" << std::endl;
		return 1;
	}
	std::stringstream ss;
	std::string buff;
	std::vector<std::string> config = readfile(argv[1]), args;
	std::vector<std::string>::iterator it;
	it = config.begin();
	while (it != config.end())
	{
		if (justwhtspc(*it))
			it = config.erase(it);
		remove_comments(*it);
		trim_end_line(*it);
		++it;
	}
	it = config.begin();
	while (it != config.end())
		std::cout << *it++ << std::endl;
	return 0;
}
