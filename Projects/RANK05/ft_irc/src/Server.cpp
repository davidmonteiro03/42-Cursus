/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:29:29 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/10 16:16:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_irc.hpp"

Server::Server(int argc, char **argv)
{
	if (argc != 3)
		throw Server::Usage();
	_info.first = std::atoi(argv[1]);
	_info.second = argv[2];
}

Server::Server(const Server &copy) { *this = copy; }

Server &Server::operator=(const Server &other)
{
	if (this != &other)
		_info = other._info;
	return (*this);
}

Server::~Server() { closeServer(EXIT_SUCCESS); }

std::vector<Client *>::iterator Server::ft_find_client(int fd)
{
	std::vector<Client *>::iterator i;
	for (i = _clients.begin(); i != _clients.end(); i++)
		if ((*i)->getFd() == fd)
			return (i);
	return (_clients.end());
}

std::vector<Client *>::iterator Server::ft_find_client(std::string username)
{
	std::vector<Client *>::iterator i;
	for (i = _clients.begin(); i != _clients.end(); i++)
		if ((*i)->getName() == username)
			return (i);
	return (_clients.end());
}

std::vector<Channel *>::iterator Server::ft_find_channel(std::string name)
{
	std::vector<Channel *>::iterator i;
	for (i = _channels.begin(); i != _channels.end(); i++)
		if ((*i)->getName() == name)
			return (i);
	return (_channels.end());
}

void Server::acceptSocket(void)
{
	struct sockaddr_in cli;
	socklen_t len;
	int client = accept(_server, (struct sockaddr *)&cli, &len);
	if (client >= 0)
	{
		FD_SET(client, &_fds);
		if (client > _nfds)
			_nfds = client;
		sendToClient(client, REQ_PASS, false);
		_status[client] = false;
	}
}

void Server::showServerCommands(int fd)
{
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	std::string header = "\n[SERVER COMMANDS]\n";
	std::vector<std::string> commands;
	commands.push_back("-> /create <channel_name> : creates a public channel\n");
	commands.push_back("-> /create <channel_name> <channel_pwd> : creates a private channel\n");
	commands.push_back("-> /show channels : shows all available channels\n");
	commands.push_back("-> /show users : shows all the users in the server\n");
	commands.push_back("-> /join <channel_name> : joins a channel\n");
	commands.push_back("-> /msg <username> <message>: sends a message to a user\n");
	commands.push_back("-> /help : shows this info\n");
	commands.push_back("-> /exit : exits the server\n\n");
	std::string message = "";
	message += header;
	for (size_t i = 0; i < commands.size(); i++)
		message += commands[i];
	sprintf(buf, "%s", message.c_str());
	send(fd, buf, strlen(buf), MSG_DONTWAIT);
}

void Server::welcomeUser(int fd, std::string user, std::string password, bool is_new_user)
{
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	if (is_new_user)
	{
		_clients.push_back(new Client(fd, user, password));
		sprintf(buf, "%s %s! ===\n", WELCOME, user.c_str());
	}
	else
	{
		std::vector<Client *>::iterator it = ft_find_client(user);
		(*it)->login();
		(*it)->setChannel(NULL);
		sprintf(buf, "%s %s! ===\n", WELCOME_BACK, user.c_str());
	}
	std::cout << GRN << user.c_str() << JOINED << COLOR_RESET << std::endl;
	send(fd, buf, strlen(buf), MSG_DONTWAIT);
	sendToClient(fd, "\nA bit lost? Type /help\n\n", false);
	sendToClient(fd, PROMPT, false);
	_session[fd] = true;
}

void Server::showUsers(int fd)
{
	char buf[BUFSIZ];
	std::vector<Client *>::iterator self = ft_find_client(fd);
	for (std::vector<Client *>::iterator i = _clients.begin(); i != _clients.end(); i++)
	{
		bzero(&buf, BUFSIZ);
		if (i == self)
			sprintf(buf, YEL "(YOU)%s\n" COLOR_RESET, (*i)->getName().c_str());
		else
		{
			if ((*i)->isLogged())
				sprintf(buf, GRN "%s\n" COLOR_RESET, (*i)->getName().c_str());
			else
				sprintf(buf, RED "%s\n" COLOR_RESET, (*i)->getName().c_str());
		}
		send(fd, buf, strlen(buf), MSG_DONTWAIT);
	}
}

void Server::showChannels(int fd)
{
	std::vector<Channel *>::iterator i;
	for (i = _channels.begin(); i != _channels.end(); i++)
			(*i)->showInfo(fd);
}

void Server::executeExit(int fd, int size)
{
	if (size == 1)
	{
		sendToClient(fd, BYE, false);
		clientLeft(fd);
	}
	else
		sendToClient(fd, BAD_USAGE, true);
}

void Server::executeShow(int fd, std::vector<std::string> args)
{
	if (args.size() != 2)
		return (sendToClient(fd, BAD_USAGE, true));
	if (args[1] != "users" && args[1] != "channels")
		return (sendToClient(fd, BAD_USAGE, true));
	if (args[1] == "users")
		showUsers(fd);
	else
		showChannels(fd);
}

void Server::executeJoin(int fd, std::vector<std::string> args)
{
	if (args.size() != 2 && args.size() != 3) return (sendToClient(fd, BAD_USAGE, true));
	std::vector<Channel *>::iterator chn_target = ft_find_channel(args[1]);
	if (chn_target == _channels.end()) return (sendToClient(fd, CHANNEL_NOTFOUND, true));
	std::vector<Client *>::iterator self = ft_find_client(fd);
	if ((*chn_target)->getPassword() == "") return ((*chn_target)->addClient(*self));
	if (args.size() == 2) return (sendToClient(fd, REQUIRED_PWD, true));
	if (args[2] != (*chn_target)->getPassword()) return (sendToClient(fd, WRONG_PASS, true));
	(*chn_target)->addClient(*self);
}

void Server::executePrivate(int fd, std::vector<std::string> args)
{
	if (args.size() <= 2)
		return (sendToClient(fd, BAD_USAGE, true));
	std::vector<Client *>::iterator sender = ft_find_client(fd);
	std::vector<Client *>::iterator receiver = ft_find_client(args[1]);
	if (receiver == _clients.end())
		return (sendToClient(fd, DOESNT_EXIST, true));
	if ((*sender)->getName() == (*receiver)->getName())
		return (sendToClient(fd, SELF_MESSAGE, true));
	if ((*receiver)->isLogged() == false)
		return (sendToClient(fd, CLIENT_OFFLINE, true));
	sendMessage(*sender, *receiver, args, 0);
}

void Server::executeCreate(int fd, std::vector<std::string> args)
{
	if (args.size() != 2 && args.size() != 3)
		return (sendToClient(fd, BAD_USAGE, true));
	std::vector<Channel *>::iterator target = ft_find_channel(args[1]);
	if (target != _channels.end())
		return (sendToClient(fd, DUPLICATE_CHANNEL, true));
	if (!isValidChannelName(args[1]))
		return (sendToClient(fd, INVALID_CHANNEL, true));
	std::vector<Client *>::iterator self = ft_find_client(fd);
	if (args.size() == 2)
		_channels.push_back(new Channel(*self, args[1]));
	else
	{
		if (!checkPassword(args[2]))
			return (sendToClient(fd, INVALID_PWD, true));
		_channels.push_back(new Channel(*self, args[1], args[2]));
	}
}

void Server::executeHelp(int fd, std::vector<std::string> args)
{
	if (args.size() != 1)
		return (sendToClient(fd, BAD_USAGE, true));
	showServerCommands(fd);
}

void Server::handleServerCommands(int fd, std::vector<std::string> args){
	if (args[0] == "/exit")
		executeExit(fd, args.size());
	else if (args[0] == "/show")
		executeShow(fd, args);
	else if (args[0] == "/join")
		executeJoin(fd, args);
	else if (args[0] == "/create")
		executeCreate(fd, args);
	else if (args[0] == "/help")
		executeHelp(fd, args);
	else
		sendToClient(fd, UNKNOWN, true);
}

void Server::handleCommands(int fd, std::string line)
{
	if (line.empty()) return (sendToClient(fd, "\033[1A \033[2K \r", false));
	std::vector<std::string> words = splitString(line);
	std::vector<Client *>::iterator it = ft_find_client(fd);
	if (words[0] == "/msg") return (executePrivate(fd, words));
	Channel *chn = (*it)->getChannel();
	if (chn == NULL) return(handleServerCommands(fd, words));
	int invitedFd = -1;
	std::string channel = "";
	if (words.size() > 1 && words[0] == "INVITE"){
		std::vector<Client *>::iterator invited = ft_find_client(words[1]);
		if (invited == _clients.end()) return (sendToClient(fd, DOESNT_EXIST, true));
		invitedFd = (*invited)->getFd();
		Channel *invitedChannel = (*invited)->getChannel();
		if (invitedChannel != NULL) channel = invitedChannel->getName();
	}
	chn->handleCommands((*it), words, invitedFd, channel);
}

void Server::createAccount(int fd, std::string user, std::string pwd)
{
	if (!processUserName(fd, user) || !processPassword(fd, pwd))
		return;
	welcomeUser(fd, user, pwd, true);
}

void Server::recoverAccount(int fd, std::string user, std::string pwd)
{
	std::vector<Client *>::iterator it = ft_find_client(user);
	if ((*it)->isLogged())
	{
		sendToClient(fd, ALREADY_LOGGED, true);
		return (sendToClient(fd, LOGIN_MSG, false));
	}
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	if ((*it)->getPassword() != pwd)
	{
		sendToClient(fd, WRONG_PASS, true);
		sendToClient(fd, LOGIN_MSG, false);
	}
	else
	{
		(*it)->setFd(fd);
		welcomeUser(fd, user, pwd, false);
	}
}

void Server::searchUser(int fd, int &status, std::vector<std::string> credentials)
{

	status = (credentials[0] == "/login") ? 1 : 2;
	std::vector<Client *>::iterator it = ft_find_client(credentials[1]);
	if (it == _clients.end())
	{
		if (status == 1)
		{
			sendToClient(fd, DOESNT_EXIST, true);
			sendToClient(fd, LOGIN_MSG, false);
		}
		else
			createAccount(fd, credentials[1], credentials[2]);
	}
	else
	{
		if (status == 2)
		{
			sendToClient(fd, DUPLICATE, true);
			sendToClient(fd, LOGIN_MSG, false);
		}
		else
			recoverAccount(fd, credentials[1], credentials[2]);
	}
}

void Server::parseMessage(int fd, std::string line)
{
	line = ft_strtrim(line);
	if (_status[fd] == false)
	{
		if (line == _info.second)
		{
			sendToClient(fd, "\n[SERVER ACCESS]\n", false);
			sendToClient(fd, "Usage: COMMAND <username> <password>\n", false);
			sendToClient(fd, LOGIN_MSG, false);
			_status[fd] = true;
		}
		else
		{
			sendToClient(fd, WRONG_PASS, true);
			sendToClient(fd, REQ_PASS, false);
		}
	}
	else
	{
		if (_session[fd] == false)
		{
			static int loginStatus = 0;
			std::vector<std::string> credentials = splitString(line);
			if (credentials.size() != 3)
			{
				sendToClient(fd, BAD_USAGE, true);
				return (sendToClient(fd, LOGIN_MSG, false));
			}
			if (credentials[0] != "/login" && credentials[0] != "/create")
			{
				sendToClient(fd, UNKNOWN, true);
				return (sendToClient(fd, LOGIN_MSG, false));
			}
			searchUser(fd, loginStatus, credentials);
		}
		else{
			handleCommands(fd, line);
			std::vector<Client *>::iterator it = ft_find_client(fd);
			if (it == _clients.end())
				return;
			if ((*it)->getChannel() == NULL)
				sendToClient(fd, PROMPT, false);
			else
			{
				char buf[BUFSIZ];
				bzero(&buf, BUFSIZ);
				sprintf(buf, CYN "[%s]> " COLOR_RESET, (*it)->getChannel()->getName().c_str());
				send(fd, buf, strlen(buf), MSG_DONTWAIT);
			}
		}
	}
}

void Server::clientLeft(int client)
{
	FD_CLR(client, &_fds);
	close(client);
	_status[client] = false;
	_session[client] = false;
	if (client == _nfds) _nfds--;
	for (size_t i = 0; i < _clients.size(); ++i)
	{
		if (_clients[i]->getFd() == client)
		{
			std::cout << RED << _clients[i]->getName() << " has left the server..." << COLOR_RESET << std::endl;
			_clients[i]->setFd(-1);
			if (_clients[i]->getChannel() != NULL) _clients[i]->getChannel()->removeClient(_clients[i]);
			_clients[i]->logout();
			break;
		}
	}
}

void Server::getInput(int client)
{
	ssize_t ret;
	char buf[BUFSIZ];
	std::string message;

	while (1)
	{
		ret = recv(client, &buf, BUFSIZ - 1, 0);
		if (ret == 0)
			return (clientLeft(client));
		message.append(buf, ret);
		std::memset(buf, 0, sizeof(buf));
		if (message.find("\n") != std::string::npos)
			break;
	}
	parseMessage(client, message);
}

void Server::closeServer(int status)
{
	for (int i = 0; i <= _nfds; i++)
	{
		if (FD_ISSET(i, &_fds))
		{
			FD_CLR(i, &_fds);
			close(i);
			_status[i] = false;
			_session[i] = false;
		}
	}
	std::vector<Client *>::iterator i;
	for (i = _clients.begin(); i != _clients.end(); i++)
		delete *i;
	_clients.clear();
	std::vector<Channel *>::iterator j;
	for (j = _channels.begin(); j != _channels.end(); j++)
		delete *j;
	_channels.clear();
	if (status == EXIT_FAILURE)
		throw Server::ServerError();
}

void Server::listenInput(void)
{
	while (1)
	{
		_events = _fds;
		if (select(_nfds + 1, &_events, NULL, NULL, NULL) == -1)
			closeServer(EXIT_FAILURE);
		for (int i = 0; i <= _nfds; i++)
		{
			if (FD_ISSET(i, &_events))
			{
				if (i == _server)
					acceptSocket();
				else
					getInput(i);
			}
		}
	}
}

void Server::createReferenceClient(void)
{
	_clients.push_back(new Client(-1, "default", "Default123#"));
	_channels.push_back(new Channel(_clients[0], "public"));
	_clients[0]->logout();
	_clients[0]->setChannel(NULL);
	_channels[0]->removeClient(_clients[0]);
}

void Server::createServer(void)
{
	_server = socket(AF_INET, SOCK_STREAM, 0);
	if (_server == -1)
		closeServer(EXIT_FAILURE);
	int opt = 1;
	if (setsockopt(_server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
		closeServer(EXIT_FAILURE);
	bzero(&_servaddr, sizeof(_servaddr));
	_servaddr.sin_family = AF_INET;
	_servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	_servaddr.sin_port = htons(_info.first);
	if (bind(_server, (const struct sockaddr *)&_servaddr, sizeof(_servaddr)) != 0 or
		listen(_server, SOMAXCONN))
		closeServer(EXIT_FAILURE);
	createReferenceClient();
	FD_ZERO(&_fds);
	FD_SET(_server, &_fds);
	_nfds = _server;
	listenInput();
}

const char *Server::Usage::what() const throw() { return ("Usage: ./ircserv <port> <password>"); }

const char *Server::ServerError::what() const throw() { return ("Server error"); }
