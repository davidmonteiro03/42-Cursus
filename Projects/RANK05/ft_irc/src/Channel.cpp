/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:48:43 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/10 16:15:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_irc.hpp"

Channel::Channel(Client *client, std::string name, std::string password)
{
	_name = name;
	if (!password.empty())
		_password = password;
	_limit = -1;
	_topic = "Default topic";
	_inviteOnly = false;
	_topicOprs = true;
	_operators.push_back(client);
	_clients.push_back(client);
	client->setChannel(this);
	std::cout << HYEL << client->getName() << " created the channel "<< _name << "!" << COLOR_RESET << std::endl;
}

Channel::Channel(const Channel &copy) { *this = copy; }

Channel::~Channel() {}

std::string Channel::getName(void) { return (_name); }

std::string Channel::getPassword(void) { return (_password); }

void Channel::setPassword(int fd, std::string password)
{
	std::vector<Client*>::iterator op_target = ft_find_operator(fd);
	if (op_target == _operators.end())
		return (sendToClient(fd, NOTAN_OPERATOR, true));
	_password = password;
}

int Channel::getLimit(void) { return (_limit); }

std::vector<Client *>::iterator Channel::ft_find_client(std::string user)
{
	std::vector<Client *>::iterator i;
	for (i = _clients.begin(); i != _clients.end(); i++)
		if ((*i)->getName() == user)
			return (i);
	return (_clients.end());
}

std::vector<Client *>::iterator Channel::ft_find_operator(std::string user)
{
	std::vector<Client *>::iterator i;
	for (i = _operators.begin(); i != _operators.end(); i++)
		if ((*i)->getName() == user)
			return (i);
	return (_operators.end());
}

std::vector<Client *>::iterator Channel::ft_find_operator(int fd)
{
	std::vector<Client *>::iterator i;
	for (i = _operators.begin(); i != _operators.end(); i++)
		if ((*i)->getFd() == fd)
			return (i);
	return (_operators.end());
}

std::vector<std::string>::iterator Channel::ft_find_invite(std::string user)
{
	std::vector<std::string>::iterator i;
	for (i = _invited.begin(); i != _invited.end(); i++)
		if (*i == user)
			return (i);
	return (_invited.end());
}

void Channel::showInfo(int fd)
{
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	if (_limit != -1)
		sprintf(buf, "#%s (%zu/%d)\n", _name.c_str(), _clients.size(), _limit);
	else
		sprintf(buf, "#%s (%zu)\n", _name.c_str(), _clients.size());
	send(fd, buf, strlen(buf), MSG_DONTWAIT);
	std::vector<Client *>::iterator i;
	for (i = _clients.begin(); i != _clients.end(); i++)
		(*i)->showInfo(fd);
}

void Channel::addClient(Client *client)
{
	int fd = client->getFd();
	if (_limit != -1 && int(_clients.size()) == _limit)	return (sendToClient(fd, CHANNEL_FULL, true));
	if (_inviteOnly && !isInvited(client->getName()) && \
		client->getName() != _operators[0]->getName()) return (sendToClient(fd, INVITEONLY_MODE, true));
	_clients.push_back(client);
	client->setChannel(this);
}

void Channel::switchMode(int fd, int flag)
{
	if (ft_find_operator(fd) == _operators.end()) return (sendToClient(fd, NOTAN_OPERATOR, true));
	if (flag == 1){
		_inviteOnly = !_inviteOnly;
		if (!_inviteOnly) _invited.clear();
	}
	else if (flag == 2) _topicOprs = !_topicOprs;
}

void Channel::removeClient(Client *client)
{
	std::vector<Client *>::iterator target = ft_find_client(client->getName());
	if (target != _clients.end())
	{
		_clients.erase(target);
		client->setChannel(NULL);
	}
}

void Channel::executeKick(int fd, std::vector<std::string> args)
{
	if (args.size() != 2)
		return (sendToClient(fd, BAD_USAGE, true));
	if (ft_find_operator(fd) == _operators.end())
		return (sendToClient(fd, NOTAN_OPERATOR, true));
	std::vector<Client *>::iterator op_target = ft_find_operator(args[1]);
	if (op_target != _operators.end())
		return (sendToClient(fd, ISAN_OPERATOR, true));
	std::vector<Client *>::iterator cli_target = ft_find_client(args[1]);
	if (cli_target == _clients.end())
		return (sendToClient(fd, USERNOT_INCHANNEL, true));
	(*cli_target)->setChannel(NULL);
	int target_fd = (*cli_target)->getFd();
	sendToClient(target_fd, KICKEDFROM_CHANNEL, false);
	sendToClient(target_fd, PROMPT, false);
	std::vector<std::string>::iterator user_kicked;
	user_kicked = ft_find_invite((*cli_target)->getName());
	if (user_kicked != _invited.end())
		_invited.erase(user_kicked);
	_clients.erase(cli_target);
}

void Channel::changeProtection(int fd, std::vector<std::string> args)
{
	if (_password == "")
	{
		if (args.size() == 2)
			return (sendToClient(fd, BAD_USAGE, true));
		return(setPassword(fd, args[2]));
	}
	if (args.size() == 3)
		return (sendToClient(fd, BAD_USAGE, true));
	setPassword(fd, "");
}

void Channel::changePrivilege(int fd, std::string username)
{
	std::vector<Client*>::iterator self = ft_find_operator(fd);
	if (self == _operators.end())
		return (sendToClient(fd, NOTAN_OPERATOR, true));
	if ((*self)->getName() == username)
		return (sendToClient(fd, SELF_PRIVILEGE, true));
	std::vector<Client*>::iterator target = ft_find_client(username);
	if (target == _clients.end())
		return (sendToClient(fd, NOTFOUND_INCHANNEL, true));
	std::vector<Client*>::iterator target2 = ft_find_operator(username);
	if (target2 == _operators.end())
		_operators.push_back(*target);
	else if (target2 == _operators.begin())
		return (sendToClient(fd, ADMIN_CHANNEL, true));
	else
		_operators.erase(target2);
}

void Channel::changeLimit(int fd, std::vector<std::string> args)
{
	std::vector<Client*>::iterator op_target = ft_find_operator(fd);
	if (op_target == _operators.end())
		return (sendToClient(fd, NOTAN_OPERATOR, true));
	if (args.size() == 3)
	{
		if (std::atoi(args[2].c_str()) < int(_clients.size()))
			return (sendToClient(fd, INVALID_LIMIT, true));
		_limit = std::atoi(args[2].c_str());
	}
	else
		_limit = -1;
}

void Channel::executeMode(Client *client, std::vector<std::string> args)
{
	int fd = client->getFd();
	if (args.size() != 2 && args.size() != 3)
		return (sendToClient(fd, BAD_USAGE, true));
	if (args[1] == "i" && args.size() == 2)
		switchMode(fd, 1);
	else if (args[1] == "t" && args.size() == 2)
		switchMode(fd, 2);
	else if (args[1] == "k")
		changeProtection(fd, args);
	else if (args[1] == "o" && args.size() == 3)
		changePrivilege(fd, args[2]);
	else if (args[1] == "l")
		changeLimit(fd, args);
	else
		sendToClient(fd, BAD_USAGE, true);
}

void Channel::sendToAll(const char *msg)
{
	std::vector<Client *>::iterator start;
	for (start = _clients.begin(); start != _clients.end(); start++)
		send((*start)->getFd(), msg, std::strlen(msg), MSG_DONTWAIT);
}

void Channel::broadcastMessage(Client *self, std::vector<std::string> args, int mode)
{
	std::vector<Client *>::iterator i;
	for (i = _clients.begin(); i != _clients.end(); i++)
		(mode == 3) ? sendInfo(self, *i, args) : sendMessage(self, *i, args, mode);
}

void Channel::executeQuit(Client *self, std::vector<std::string> args)
{
	if (args.size() != 1)
		return (sendToClient(self->getFd(), BAD_USAGE, true));
	this->removeClient(self);
	self->setChannel(NULL);
}

bool Channel::isInvited(std::string client){
	for(size_t i = 0; i < _invited.size(); i++)
		if (_invited[i] == client) return true;
	return false;
}

void Channel::showChannelTopic(int fd)
{
	std::string temp = "The topic is \'" + _topic + "\'\n";
	sendToClient(fd, temp.c_str(), false);
}

void Channel::executeTopic(Client *host, std::vector<std::string> args)
{
	if (args.size() == 1) return (showChannelTopic(host->getFd()));
	if (ft_find_operator(host->getFd()) == _operators.end() && _topicOprs)
		return (sendToClient(host->getFd(), TOPICRESTRICTIONS, true));
	std::string topic = "";
	for (size_t i = 1; i < args.size(); i++)
		topic += (i > 1) ? " " + args[i] : args[i];
	_topic = topic;
	args.clear();
	args.push_back(topic);
	broadcastMessage(host, args, 3);
}

void Channel::executeInvite(Client *host, std::vector<std::string> args, int invitedFd, std::string chn)
{
	int fd = host->getFd();
	if (args.size() != 2) return (sendToClient(fd, BAD_USAGE, true));
	if (ft_find_operator(fd) == _operators.end()) return(sendToClient(fd, NOTAN_OPERATOR, true));
	if (ft_find_client(args[1]) != _clients.end()) return(sendToClient(fd, USERISINCHANNEL, true));
	if (isInvited(args[1])) return (sendToClient(fd, ALREADYINVITED, true));
	_invited.push_back(args[1]);
	sendToClient(fd, INVITESENT, false);
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	sprintf(buf, CYN "\033[2K \rYou were invited to %s\n" COLOR_RESET, _name.c_str());
	send(invitedFd, buf, strlen(buf), MSG_DONTWAIT);
	if (chn == "") sendToClient(invitedFd, PROMPT, false);
	else
	{
		char buf[BUFSIZ];
		bzero(&buf, BUFSIZ);
		sprintf(buf, CYN "[%s]> " COLOR_RESET, chn.c_str());
		send(invitedFd, buf, strlen(buf), MSG_DONTWAIT);
	}
}

void Channel::showChannelCommands(int fd, std::vector<std::string> args)
{
	if (args.size() != 1) return (sendToClient(fd, BAD_USAGE, true));
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	std::string header = "\n[CHANNEL OPERATOR COMMANDS]\n";
	std::vector<std::string> commands;
	commands.push_back("* KICK - Eject a client from the channel\n");
	commands.push_back("* INVITE - Invite a client to a channel\n");
	commands.push_back("* TOPIC - Change or view the channel topic\n");
	commands.push_back("* MODE - Change the channel's mode:\n");
	commands.push_back("\t i: Set/remove Invite-only channel\n");
	commands.push_back("\t t: Set/remove the restrictions of the TOPIC command to channel operators\n");
	commands.push_back("\t k: Set/remove the channel key (password)\n");
	commands.push_back("\t o: Give/take channel operator privilege\n");
	commands.push_back("\t l: Set/remove the user limit to channel\n");
	commands.push_back("* HELP - shows this info\n");
	commands.push_back("* QUIT - quits the channel\n\n");
	commands.push_back("-> /msg <username> <message>: sends a message to a user\n\n");
	std::string message = "";
	message += header;
	for (size_t i = 0; i < commands.size(); i++)
		message += commands[i];
	sprintf(buf, "%s", message.c_str());
	send(fd, buf, strlen(buf), MSG_DONTWAIT);
}

void Channel::handleCommands(Client *client, std::vector<std::string> args, int invitedFd, std::string chn){
	int fd = client->getFd();
	if (args[0] == "KICK") return (executeKick(fd, args));
	if (args[0] == "INVITE") return(executeInvite(client, args, invitedFd, chn));
	if (args[0] == "TOPIC") return (executeTopic(client, args));
	if (args[0] == "MODE") return (executeMode(client, args));
	if (args[0] == "HELP") return(showChannelCommands(fd, args));
	if (args[0] == "QUIT") return(executeQuit(client, args));
	return (broadcastMessage(client, args, 1));
}
