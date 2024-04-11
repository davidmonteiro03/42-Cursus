/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:55:33 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/08 21:09:45 by riolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_irc.hpp"

Client::Client(int fd, std::string name, std::string password)
{
	_fd = fd;
	_name = name;
	_password = password;
	_isLogged = true;
	_channel = NULL;
	std::cout << BCYN << "NEW CLIENT " << _name << COLOR_RESET << std::endl;
}

Client::Client(const Client &copy) { *this = copy; }

Client &Client::operator=(const Client &other)
{
	if (this != &other)
	{
		_fd = other._fd;
		_name = other._name;
		_password = other._password;
		_isLogged = other._isLogged;
	}
	return (*this);
}

Client::~Client() {}

std::string Client::getName(void) { return (_name); }

int Client::getFd(void) { return (_fd); }

bool Client::isLogged(void) { return (_isLogged); }

std::string Client::getPassword(void) { return (_password); }

Channel* Client::getChannel(void) { return (_channel); }

void Client::setFd(int fd) { _fd = fd; }

void Client::setChannel(Channel *channel) { _channel = channel; }

void Client::logout(void) { _isLogged = false; }

void Client::login(void) { _isLogged = true; }

void Client::showInfo(int fd)
{
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	sprintf(buf, "\t@%s\n", _name.c_str());
	send(fd, buf, strlen(buf), MSG_DONTWAIT);
}