/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:26:23 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 22:09:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

Server::Server(int argc, char **argv)
{
	if (argc != 3 || (argc == 3 && (argv[1][0] == '\0' || argv[2][0] == '\0')))
		throw Server::ErrorUsage();
	_socket = newSocket(argv[1]);
	_port = std::atoi(argv[1]);
	_password = argv[2];
}

Server::~Server()
{
	for (int fd = 0; fd <= _fdmax; fd++)
	{
		if (FD_ISSET(fd, &_fds.all))
		{
			FD_CLR(fd, &_fds.all);
			close(fd);
			if (_clients[fd] != NULL)
				delete _clients[fd];
		}
	}
	_clients.clear();
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
		delete *it;
	_channels.clear();
}

void Server::execute(void)
{
	FD_ZERO(&_fds.all);
	FD_SET(_socket.fd, &_fds.all);
	_fdmax = _socket.fd;
	while (42)
	{
		_fds.read = _fds.write = _fds.all;
		if (select(_fdmax + 1, &_fds.read, &_fds.write, NULL, NULL) < 0)
			continue;
		for (int fd = 0; fd <= _fdmax; fd++)
		{
			if (!FD_ISSET(fd, &_fds.read))
				continue;
			if (fd == _socket.fd)
				connect();
			else
				handle(fd);
		}
	}
}

void Server::getInfo(void) const
{
	std::strcpy(hostname, _socket.hostname);
	ip = _socket.ip;
	std::cout << std::endl;
	welcomeMessage();
	std::cout << std::endl;
	std::cout << "\t\tServer Information" << std::endl
			  << std::endl;
	std::cout << "\t" << std::setw(8) << std::left << "hostname" << ": " << hostname << std::endl;
	std::cout << "\t" << std::setw(8) << std::left << "ip" << ": " << ip << std::endl;
	std::cout << "\t" << std::setw(8) << std::left << "port" << ": " << _port << std::endl;
	std::cout << "\t" << std::setw(8) << std::left << "password" << ": '" << _password << "'" << std::endl
			  << std::endl;
}

bool Server::connect(void)
{
	t_socket client;
	client.len = sizeof(client.addr);
	client.fd = accept(_socket.fd, (struct sockaddr *)&client.addr, &client.len);
	if (client.fd >= 0)
	{
		if (client.fd > _fdmax)
			_fdmax = client.fd;
		FD_SET(client.fd, &_fds.all);
		if (_clients[client.fd] == NULL)
			_clients[client.fd] = new Client(client.fd);
		_msgs[client.fd] = "";
		logs("server", getInfoClient(_clients[client.fd]) + " " + LOG_CONNECTED);
		return (true);
	}
	return (false);
}

bool Server::disconnect(int fd, t_string reason)
{
	FD_CLR(fd, &_fds.all);
	close(fd);
	if (fd == _fdmax)
		--_fdmax;
	_msgs[fd] = "";
	if (_clients[fd] != NULL)
	{
		t_channels::iterator it;
		for (it = _channels.begin(); it != _channels.end(); it++)
		{
			if (reason.empty())
				_clients[fd]->partChannel(*it);
			else
				_clients[fd]->partChannel(*it, reason);
		}
		removeEmptyChannels();
		logs("server", getInfoClient(_clients[fd]) + " " + LOG_DISCONNECTED);
		delete _clients[fd];
		_clients[fd] = NULL;
	}
	return (false);
}

bool Server::handle(int fd)
{
	char buf[BUFSIZ];
	std::memset(buf, 0, BUFSIZ);
	int ret = recv(fd, buf, sizeof(buf) - 1, MSG_DONTWAIT);
	if (ret < 0)
	{
		if (errno == EAGAIN || errno == EWOULDBLOCK)
			return (true);
		return (disconnect(fd, t_string()));
	}
	if (ret == 0)
		return (disconnect(fd, t_string()));
	_msgs[fd] += buf;
	while (_msgs[fd].find("\n") != t_string::npos)
	{
		t_string line = _msgs[fd].substr(0, _msgs[fd].find("\n"));
		_msgs[fd] = _msgs[fd].substr(_msgs[fd].find("\n") + 1);
		parseLine(fd, line);
	}
	return (true);
}

bool Server::parseLine(int fd, t_string line)
{
	if (line.find('\r') != t_string::npos)
		line.erase(line.find('\r'));
	t_input input = getInput(line);
	if (input.first.empty())
		return (false);
	if (input.first[0] == "CAP")
		return (false);
	if (input.first[0] == "PASS")
		return (executePass(fd, input, input.first[0]));
	if (input.first[0] == "NICK")
		return (executeNick(fd, input, input.first[0]));
	if (input.first[0] == "USER")
		return (executeUser(fd, input, input.first[0]));
	if (input.first[0] == "JOIN")
		return (executeJoin(fd, input, input.first[0]));
	if (input.first[0] == "MODE")
		return (executeMode(fd, input, input.first[0]));
	if (input.first[0] == "TOPIC")
		return (executeTopic(fd, input, input.first[0]));
	if (input.first[0] == "KICK")
		return (executeKick(fd, input, input.first[0]));
	if (input.first[0] == "INVITE")
		return (executeInvite(fd, input, input.first[0]));
	if (input.first[0] == "WHO")
		return (executeWho(fd, input, input.first[0]));
	if (input.first[0] == "PART")
		return (executePart(fd, input, input.first[0]));
	if (input.first[0] == "PRIVMSG")
		return (executePrivMsg(fd, input, input.first[0]));
	if (input.first[0] == "QUIT")
		return (executeQuit(fd, input));
	sendMessage(fd, ERR_UNKNOWNCOMMAND(hostname, _clients[fd]->getNickname(), input.first[0]));
	return (false);
}

bool Server::executePass(int fd, t_input input, t_string command)
{
	if (_clients[fd]->isLogged() == true)
		return (false);
	t_string pass;
	if (input.first.size() == 1)
		pass = input.second;
	else
		pass = input.first[1];
	if (pass.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	if (pass != _password)
		return (sendMessage(fd, ERR_PASSWDMISMATCH(hostname, _clients[fd]->getNickname(), pass)));
	Client oldClient = *_clients[fd];
	_clients[fd]->login();
	if (oldClient.getStatus() != _clients[fd]->getStatus() &&
		_clients[fd]->getStatus() == 1)
		return (welcomeMessage(_clients[fd]));
	return (true);
}

bool Server::executeNick(int fd, t_input input, t_string command)
{
	if (!_clients[fd]->getNick().empty() && _clients[fd]->getStatus() == false)
		return (false);
	t_string nick;
	if (input.first.size() == 1)
		nick = input.second;
	else
		nick = input.first[1];
	if (nick.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	if (checkName(nick) == false)
	{
		if (_clients[fd]->getNick().empty())
		{
			sendMessage(fd, "Sorry... You need to enter a valid nickname...\n");
			sendMessage(fd, "Exiting...\n");
			return (disconnect(fd, "Erroneus nickname"));
		}
		return (sendMessage(fd, ERR_ERRONEUSNICKNAME(hostname, _clients[fd]->getNickname(), nick)));
	}
	for (int i = 0; i <= _fdmax; i++)
	{
		if (FD_ISSET(i, &_fds.all) && i != _socket.fd && i != fd &&
			_clients[i]->getNick() == nick)
		{
			if (_clients[fd]->getNick().empty())
			{
				sendMessage(fd, "Sorry... You need to enter a non-existing nickname...\n");
				sendMessage(fd, "Exiting...\n");
				return (disconnect(fd, "Nickname is already in use"));
			}
			return (sendMessage(fd, ERR_NICKNAMEINUSE(hostname, _clients[fd]->getNickname(), nick)));
		}
	}
	logs("server", getInfoClient(_clients[fd]) + " " + LOG_NICK(nick));
	Client oldClient = *_clients[fd];
	_clients[fd]->setNick(nick);
	sendMessage(fd, RPL_NICKNAME(oldClient.getClient(), nick));
	_clients[fd]->warnOtherUsers(RPL_NICKNAME(oldClient.getClient(), nick));
	if (oldClient.getStatus() != _clients[fd]->getStatus() &&
		_clients[fd]->getStatus() == true)
		return (welcomeMessage(_clients[fd]));
	return (true);
}

bool Server::executeUser(int fd, t_input input, t_string command)
{
	if (_clients[fd]->isLogged() == false && !_clients[fd]->getUser().empty())
		return (false);
	t_string user, real;
	if (input.first.size() < 4 || input.second.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	user = input.first[1];
	real = input.second;
	if (!_clients[fd]->getUser().empty())
		return (sendMessage(fd, ERR_ALREADYREGISTERED(hostname, _clients[fd]->getNickname())));
	if (!checkName(user))
	{
		sendMessage(fd, "Sorry... You need to enter a valid username...\n");
		sendMessage(fd, "Exiting...\n");
		return (disconnect(fd, "Erroneus username"));
	}
	for (int i = 0; i <= _fdmax; i++)
	{
		if (FD_ISSET(i, &_fds.all) && i != _socket.fd && i != fd &&
			_clients[i]->getUser() == user)
		{
			sendMessage(fd, "Sorry... You need to enter a non-existing username...\n");
			sendMessage(fd, "Exiting...\n");
			return (disconnect(fd, "Username is already in use"));
		}
	}
	logs("server", getInfoClient(_clients[fd]) + " " + LOG_USER(user, real));
	Client oldClient = *_clients[fd];
	_clients[fd]->setUser(user, real);
	if (oldClient.getStatus() != _clients[fd]->getStatus() &&
		_clients[fd]->getStatus() == true)
		return (welcomeMessage(_clients[fd]));
	return (true);
}

bool Server::joinClientChannel(Client *client, t_string channel, t_string key)
{
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
		if ((*it)->getName() == channel)
			return (joinExistingChannel(client, *it, key));
	return (joinNewChannel(client, channel));
}

bool Server::joinNewChannel(Client *client, t_string channel)
{
	Channel *new_channel = new Channel(channel);
	logs("server", client->getNickname() + " " + LOG_JOIN(channel));
	new_channel->addBot(new Bot(channel, new_channel));
	new_channel->addOperator(client, true);
	client->joinChannel(new_channel);
	_channels.push_back(new_channel);
	sendMessage(client->getFd(), RPL_JOIN(client->getClient(), channel));
	sendMessage(client->getFd(), RPL_MODE(client->getClient(), channel, "+t", t_string()));
	sendMessage(client->getFd(), RPL_NAMREPLY(hostname, client->getNickname(), "=", channel, "@" + client->getNickname()));
	return (sendMessage(client->getFd(), RPL_ENDOFNAMES(hostname, client->getNickname(), channel)));
}

bool Server::joinExistingChannel(Client *client, Channel *channel, t_string key)
{
	if (channel->isInChannel(client->getNick()))
		return (false);
	if (channel->getLimit() > 0 && channel->countUsers() == channel->getLimit())
		return (sendMessage(client->getFd(), ERR_CHANNELISFULL(hostname, client->getNickname(), channel->getName())));
	if (channel->getInviteFlag() && !channel->isInvited(client))
		return (sendMessage(client->getFd(), ERR_INVITEONLYCHAN(hostname, client->getNickname(), channel->getName())));
	if (!channel->getKey().empty() && key != channel->getKey())
		return (sendMessage(client->getFd(), ERR_BADCHANNELKEY(hostname, client->getNickname(), channel->getName())));
	logs("server", client->getNickname() + " " + LOG_JOIN(channel->getName()));
	logs(channel->getName(), LOG_JOIN2(client->getNick(), client->getUsername()));
	client->joinChannel(channel);
	channel->addUser(client, true);
	t_string targets = getTargets(channel);
	sendMessage(client->getFd(), RPL_JOIN(client->getClient(), channel->getName()));
	sendMessage(client->getFd(), RPL_NAMREPLY(hostname, client->getNickname(), "@", channel->getName(), targets));
	sendMessage(client->getFd(), RPL_ENDOFNAMES(hostname, client->getNickname(), channel->getName()));
	channel->broadcast(client, RPL_JOIN2(client->getClient(), channel->getName()));
	t_string modes = getModes(channel);
	sendMessage(client->getFd(), RPL_CHANNELMODEIS(hostname, client->getNickname(), channel->getName(), modes));
	sendMessage(client->getFd(), RPL_CREATIONTIME(hostname, client->getNickname(), channel->getName(), channel->getCreationTime()));
	channel->removeInvited(client);
	return (true);
}

bool Server::executeJoin(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_args args = getArgsPro(input, 1);
	if (args.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	t_args channels, keys;
	if (args.size() >= 1)
		channels = ft_split(args[0], ',');
	if (args.size() >= 2)
		keys = ft_split(args[1], ',');
	for (size_t i = 0; i < channels.size(); i++)
	{
		if (!checkChannel(channels[i]))
		{
			sendMessage(fd, ERR_INVALIDCHANNELNAME(hostname, _clients[fd]->getNickname(), channels[i]));
			continue;
		}
		if (i >= keys.size())
			joinClientChannel(_clients[fd], channels[i], t_string());
		else
			joinClientChannel(_clients[fd], channels[i], keys[i]);
	}
	return (true);
}

bool Server::executeMode(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_args args = getArgsPro(input, 1);
	if (args.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	t_args channels, arguments = copyFromPos(args, 2);
	t_string modes;
	if (args.size() >= 1)
		channels = ft_split(args[0], ',');
	if (args.size() >= 2)
		modes = args[1];
	if (modes.empty())
		for (size_t i = 0; i < channels.size(); i++)
			showChannelModes(_clients[fd], channels[i]);
	else
		for (size_t i = 0; i < channels.size(); i++)
			changeChannelModes(_clients[fd], channels[i], getModeFlags(modes), arguments);
	return (true);
}

Client *Server::findClient(t_string name)
{
	for (int fd = 0; fd <= _fdmax; fd++)
		if (FD_ISSET(fd, &_fds.all) &&
			_clients[fd] != NULL &&
			_clients[fd]->getStatus() == true &&
			_clients[fd]->getNick() == name)
			return (_clients[fd]);
	return (NULL);
}

bool Server::executeInvite(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_args args = getArgsPro(input, 1);
	if (args.size() <= 1)
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	if (args[0][0] == '#')
		return (sendMessage(fd, "You can't invite a channel or a bot\n"));
	if (findClient(args[0]) == NULL)
		return (sendMessage(fd, ERR_NOSUCHNICK(hostname, _clients[fd]->getNickname(), args[0])));
	Client *invited = findClient(args[0]);
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == args[1])
		{
			if (!(*it)->isInChannel(_clients[fd]))
				return (sendMessage(fd, ERR_NOTONCHANNEL(hostname, _clients[fd]->getNickname(), (*it)->getName())));
			if (!(*it)->isOperator(_clients[fd]))
				return (sendMessage(fd, ERR_CHANOPRIVSNEEDED(hostname, _clients[fd]->getNickname(), (*it)->getName())));
			if ((*it)->isInChannel(args[0]))
				return (sendMessage(fd, ERR_USERONCHANNEL(hostname, _clients[fd]->getNickname(), (*it)->getName())));
			return ((*it)->addInvited(_clients[fd], invited), true);
		}
	}
	return (sendMessage(fd, ERR_NOSUCHCHANNEL(hostname, _clients[fd]->getClient(), args[1])));
}

bool Server::executeTopic(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_args args = getArgsPro(input, 1);
	if (args.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == args[0])
		{
			if (args.size() == 1)
				return ((*it)->showTopic(_clients[fd]));
			return ((*it)->changeTopic(_clients[fd], args[1]));
		}
	}
	return (sendMessage(fd, ERR_NOSUCHCHANNEL(hostname, _clients[fd]->getNickname(), args[0])));
}

bool Server::executeKick(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_args args = getArgsPro(input, 1);
	if (args.empty() || args.size() == 1)
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == args[0])
		{
			if ((*it)->getName() + "_BOT" == args[1])
				return (sendMessage(fd, RPL_MSG((*it)->getBotClient()->getClient(), _clients[fd]->getNickname(), "You can't touch me. I'm a BOT!")));
			Client *victim = findClient(args[1]);
			if (victim == NULL)
				return (sendMessage(fd, ERR_NOSUCHNICK(hostname, _clients[fd]->getNickname(), args[1])));
			(*it)->kickUser(_clients[fd], victim, args);
			return (removeEmptyChannels(), true);
		}
	}
	return (sendMessage(fd, ERR_NOSUCHCHANNEL(hostname, _clients[fd]->getNickname(), args[0])));
}

bool Server::executeWho(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_string arg;
	if (input.first.size() == 1)
		arg = input.second;
	else
		arg = input.first[1];
	if (arg.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == arg)
		{
			sendMessage(fd, RPL_NAMREPLY(hostname, _clients[fd]->getNickname(), "=", arg, getTargets(*it)));
			return (sendMessage(fd, RPL_ENDOFNAMES(hostname, _clients[fd]->getNickname(), arg)));
		}
	}
	return (sendMessage(fd, ERR_NOSUCHCHANNEL(hostname, _clients[fd]->getNickname(), arg)));
}

bool Server::executePart(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_args args = getArgsPro(input, 1);
	if (args.empty())
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	t_args channels;
	t_string reason;
	if (args.size() >= 1)
		channels = ft_split(args[0], ',');
	if (args.size() >= 2)
		reason = args[1];
	for (size_t i = 0; i < channels.size(); i++)
		partClientChannel(_clients[fd], channels[i], reason);
	return (true);
}

bool Server::executeQuit(int fd, t_input input)
{
	t_args args = getArgsPro(input, 1);
	t_string reason;
	if (!args.empty())
		reason = args[0];
	disconnect(fd, reason);
	return (true);
}

bool Server::executePrivMsg(int fd, t_input input, t_string command)
{
	if (_clients[fd]->getStatus() == false)
		return (sendMessage(fd, ERR_NOTREGISTERED(hostname, _clients[fd]->getNickname())));
	t_args args = getArgsPro(input, 1);
	if (args.size() < 2)
		return (sendMessage(fd, ERR_NEEDMOREPARAMS(hostname, _clients[fd]->getNickname(), command)));
	t_args targets = ft_split(args[0], ',');
	t_string message = args[1];
	t_args::iterator it;
	for (it = targets.begin(); it != targets.end(); it++)
	{
		if (it->at(0) == '#')
			sendToChannel(_clients[fd], *it, message);
		else
			sendToUser(_clients[fd], *it, message);
	}
	return (true);
}

void Server::partClientChannel(Client *client, t_string channel, t_string reason)
{
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == channel)
		{
			if ((*it)->isInChannel(client) == false)
				return (sendMessage(client->getFd(), ERR_NOTONCHANNEL(hostname, client->getNickname(), channel)), void());
			if (reason.empty())
				client->partChannel(*it);
			else
				client->partChannel(*it, reason);
			return (removeEmptyChannels());
		}
	}
	sendMessage(client->getFd(), ERR_NOSUCHCHANNEL(hostname, client->getNickname(), channel));
}

bool Server::showChannelModes(Client *client, t_string channel)
{
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == channel)
		{
			(*it)->showModes(client);
			return (true);
		}
	}
	return (sendMessage(client->getFd(), ERR_NOSUCHCHANNEL(hostname, client->getNickname(), channel)));
}

bool Server::changeChannelModes(Client *client, t_string channel, t_args flags, t_args arguments)
{
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == channel)
		{
			if (!(*it)->isInChannel(client))
				return (sendMessage(client->getFd(), ERR_NOTONCHANNEL(hostname, client->getNickname(), channel)));
			if (!(*it)->isOperator(client))
				return (sendMessage(client->getFd(), ERR_CHANOPRIVSNEEDED(hostname, client->getNickname(), channel)));
			t_string flags_str, args_str;
			size_t j = 0;
			for (size_t i = 0; i < flags.size(); i++)
			{
				if (std::strchr(MODE_CHARSET, flags[i][1]) == NULL)
					continue;
				if (std::strchr("it", flags[i][1]) == NULL &&
					flags[i] != "-l")
				{
					if (j < arguments.size())
					{
						if (flags[i][1] == 'o' && channel + "_BOT" == arguments[j])
							sendMessage(client->getFd(), RPL_MSG((*it)->getBotClient()->getClient(), client->getNickname(), "You can't touch me. I'm a BOT!"));
						else if (flags[i][1] == 'o' && findClient(arguments[j]) == NULL)
							sendMessage(client->getFd(), ERR_NOSUCHNICK(hostname, client->getNickname(), arguments[j]));
						else
							(*it)->changeMode(client, flags[i], arguments[j], flags_str, args_str);
					}
					j++;
				}
				else
					(*it)->changeMode(client, flags[i], flags_str);
			}
			sendMessage(client->getFd(), RPL_MODE(client->getClient(), (*it)->getName(), flags_str, args_str));
			(*it)->broadcast(client, RPL_MODE(client->getClient(), (*it)->getName(), flags_str, args_str));
			return (true);
		}
	}
	return (sendMessage(client->getFd(), ERR_NOSUCHCHANNEL(hostname, client->getNickname(), channel)));
}

bool Server::sendToUser(Client *sender, t_string target, t_string message)
{
	Client *receiver = findClient(target);
	if (receiver == NULL)
		return (sendMessage(sender->getFd(), ERR_NOSUCHNICK(hostname, sender->getNickname(), target)));
	logs("server", LOG_PRIVMSG(sender->getNick(), receiver->getNick(), message));
	return (sendMessage(receiver->getFd(), RPL_MSG(sender->getClient(), receiver->getNickname(), message)));
}

bool Server::sendToChannel(Client *sender, t_string channel, t_string message)
{
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end(); it++)
	{
		if ((*it)->getName() == channel)
		{
			if (!(*it)->isInChannel(sender))
				return (sendMessage(sender->getFd(), ERR_NOTONCHANNEL(hostname, sender->getNickname(), (*it)->getName())));
			logs((*it)->getName(), LOG_PRIVMSG(sender->getNick(), channel, message));
			(*it)->broadcast(sender, RPL_MSG(sender->getClient(), channel, message));
			return (true);
		}
	}
	return (sendMessage(sender->getFd(), ERR_NOSUCHCHANNEL(hostname, sender->getNickname(), channel)));
}

void Server::removeEmptyChannels(void)
{
	t_channels::iterator it;
	for (it = _channels.begin(); it != _channels.end();)
	{
		if ((*it)->getUsers().size() == 0 &&
			(*it)->getOperators().size() <= 1)
		{
			delete *it;
			it = _channels.erase(it);
		}
		else
			++it;
	}
}

const char *Server::ErrorUsage::what() const throw()
{
	return ("Server: usage: ./ircserv <port> <password>");
}

const char *Server::InvalidPort::what() const throw()
{
	return ("Server: invalid port");
}

const char *Server::ErrorCreatingSocket::what() const throw()
{
	return ("Server: error creating socket");
}

const char *Server::ErrorBindingSocket::what() const throw()
{
	return ("Server: error binding socket");
}

const char *Server::ErrorListenSocket::what() const throw()
{
	return ("Server: error listening socket");
}

const char *Server::ErrorGettingHostname::what() const throw()
{
	return ("Server: error getting hostname");
}

const char *Server::ErrorGettingIP::what() const throw()
{
	return ("Server: error getting IP");
}
