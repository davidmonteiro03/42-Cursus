/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:29:29 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/27 11:45:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Server.hpp"

Server::Server(int argc, char **argv)
{
	if (argc != 3)
		throw Server::Usage();
	_info.first = std::atoi(argv[1]);
	_info.second = argv[2];
}

Server::Server(const Server& copy)
{
	*this = copy;
}

Server& Server::operator=(const Server& other)
{
	if (this != &other)
		this->_info = other._info;
	return (*this);
}

Server::~Server()
{
}

void Server::execute(void)
{
	std::cout << "Server port: " << _info.first << std::endl;
	std::cout << "Server pass: " << _info.second << std::endl;
}

const char* Server::Usage::what() const throw()
{
	return ("Usage: ./ircserv <port> <password>");
}
