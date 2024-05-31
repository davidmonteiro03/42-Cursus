/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:17:04 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 13:19:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

Client::Client(int fd) : _fd(fd), _logged(false), _user(t_string()), _nick(t_string()), _real(t_string())
{
	_status[0] = false;
	_status[1] = false;
	_status[2] = false;
}

Client::Client(t_string name) : _fd(-1), _logged(true), _user(name), _nick(name), _real(name)
{
	_status[0] = true;
	_status[1] = true;
	_status[2] = true;
}

Client::~Client() { _channels.clear(); }

int Client::getFd(void) const { return (_fd); }

bool Client::isLogged(void) const { return (_logged); }

bool Client::getStatus(void) const
{
	for (int i = 0; i < 3; i++)
		if (_status[i] == false)
			return (false);
	return (true);
}

bool Client::getStatus(int pos) const
{
	if (pos < 0 || pos > 2)
		return (false);
	return (_status[pos]);
}

t_string Client::getUser(void) const { return (_user); }

t_string Client::getNick(void) const { return (_nick); }

t_string Client::getClient(void) const { return (getClientSintax(this)); }

t_string Client::getNickname(void) const { return (getNicknameSintax(this)); }

t_string Client::getUsername(void) const { return (getUsernameSintax(this)); }

void Client::login(void)
{
	_logged = true;
	setstatus(PASS);
}

void Client::setstatus(int pos)
{
	if (pos < 0 || pos > 2)
		return;
	if (_status[pos] == true)
		return;
	_status[pos] = true;
}

void Client::setUser(t_string user, t_string real)
{
	_user = user;
	_real = real;
	setstatus(USER);
}

void Client::setNick(t_string nick)
{
	_nick = nick;
	setstatus(NICK);
}

void Client::joinChannel(Channel *channel) { _channels.push_back(channel); }

void Client::partChannel(Channel *channel)
{
	if (channel == NULL)
		return ;
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if (*it == channel)
		{
			logs((*it)->getName(), LOG_PART1(getNickname(), getUsername()));
			sendMessage(_fd, RPL_PART1(getClient(), (*it)->getName()));
			(*it)->removeUser(this);
			(*it)->removeOperator(this);
			(*it)->broadcast(this, RPL_PART1(getClient(), (*it)->getName()));
			_channels.erase(it);
			return;
		}
	}
}

void Client::partChannel(Channel *channel, t_string reason)
{
	if (channel == NULL)
		return ;
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if (*it == channel)
		{
			logs((*it)->getName(), LOG_PART2(getNickname(), getUsername(), reason));
			sendMessage(_fd, RPL_PART2(getClient(), (*it)->getName(), reason));
			(*it)->removeUser(this);
			(*it)->removeOperator(this);
			(*it)->broadcast(this, RPL_PART2(getClient(), (*it)->getName(), reason));
			_channels.erase(it);
			return;
		}
	}
	sendMessage(_fd, ERR_NOTONCHANNEL(hostname, getNickname(), channel->getName()));
}

void Client::warnOtherUsers(t_string message)
{
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
		(*it)->broadcast(this, message);
}
