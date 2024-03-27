/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:29:29 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/27 13:08:00 by dcaetano         ###   ########.fr       */
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
	ft_close();
}

void Server::ft_fail(void)
{
	for (int i = 0; i <= _nfds; ++i)
		if (FD_ISSET(i, &_fds))
			close(i);
	throw Server::ServerError();
}

void Server::ft_close(void)
{
	close(_server);
}

void Server::ft_create(void)
{
	_server = socket(AF_INET, SOCK_STREAM, 0);
	if (_server == -1)
		throw Server::ServerError();
	bzero(&_servaddr, sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	_servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	_servaddr.sin_port = htons(_info.first);
	if (bind(_server, (const struct sockaddr *)&_servaddr, sizeof(_servaddr)) != 0 || \
		listen(_server, 100))
	{
		ft_close();
		throw Server::ServerError();
	}
	FD_ZERO(&_fds);
	FD_SET(_server, &_fds);
	char buf[BUFSIZ];
	_nfds = _server;
	while (1)
	{
		_events = _fds;
		if (select(_nfds + 1, &_events, NULL, NULL, NULL) == -1)
			ft_fail();
		for (int i = 0; i <= _nfds; ++i)
		{
			if (FD_ISSET(i, &_fds))
			{
				if (i == _server)
				{
					struct sockaddr_in cli;
					socklen_t len;
					int client = accept(_server, (struct sockaddr *)&cli, &len);
					if (client >= 0)
					{
						FD_SET(client, &_fds);
						if (client > _nfds)
							_nfds = client;
						send(client, PASSWORD_REQUEST, std::strlen(PASSWORD_REQUEST), 0);
					}
				}
				else
				{
					bzero(buf, BUFSIZ);
					ssize_t ret = recv(i, buf, BUFSIZ - 1, 0);
					if (ret == 0)
					{
						// fechou conexao
					}
					else if (ret > 0)
					{
						// ler msg
					}
				}
			}
		}
	}
}

const char* Server::Usage::what() const throw()
{
	return ("Usage: ./ircserv <port> <password>");
}

const char* Server::ServerError::what() const throw()
{
	return ("Server error");
}
