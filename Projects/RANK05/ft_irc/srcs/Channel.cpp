/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:48:46 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 17:37:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

Channel::Channel(t_string name) : _name(name), _key(t_string()), _topic(t_string())
{
	_inviteOnly = false;
	_topicRest = true;
	_limit = std::numeric_limits<size_t>::max();
	_creationTime = std::time(0);
}

Channel::~Channel()
{
	if (getBotClient() != NULL)
		delete getBotClient();
	if (_bot != NULL)
		delete _bot;
	_users.clear();
	_operators.clear();
	_invited.clear();
}

t_string Channel::getName(void) const { return (_name); }

t_string Channel::getKey(void) const { return (_key); }

t_string Channel::getTopic(void) const { return (_topic); }

t_users Channel::getUsers(void) const { return (_users); }

t_users Channel::getOperators(void) const { return (_operators); }

bool Channel::getInviteFlag(void) const { return (_inviteOnly); }

bool Channel::getTopicFlag(void) const { return (_topicRest); }

size_t Channel::getLimit(void) const { return (_limit); }

t_string Channel::getCreationTime(void) const
{
	std::stringstream ss;
	ss << _creationTime;
	return (ss.str());
}

void Channel::addUser(Client *user, bool mode)
{
	_users.push_back(user);
	if (mode)
		_bot->addStats(user);
}

void Channel::addOperator(Client *op, bool mode)
{
	_operators.push_back(op);
	if (mode)
		_bot->addStats(op);
}

size_t Channel::countUsers() { return (_users.size() + _operators.size()); }

void Channel::addInvited(Client *client, Client *inv)
{
	for (size_t i = 0; i < _invited.size(); i++)
		if (_invited[i]->getNick() == inv->getNick())
			return;
	_invited.push_back(inv);
	logs(_name, LOG_INVITE(client->getNick(), inv->getNick(), _name));
	sendMessage(client->getFd(), RPL_INVITING(hostname, _name, inv->getNick()));
	sendMessage(inv->getFd(), RPL_INVITE(client->getNick(), _name, inv->getNick()));
	_bot->updateStats(client);
}

void Channel::addBot(Bot *bot)
{
	_bot = bot;
	Client *bot_client = new Client(_bot->getName());
	addOperator(bot_client, false);
}

void Channel::removeUser(Client *user)
{
	t_users::iterator it;
	for (it = _users.begin(); it != _users.end(); it++)
	{
		if (*it == user)
		{
			_users.erase(it);
			return (_bot->removeClient(user));
		}
	}
}

void Channel::removeInvited(Client *invited)
{
	t_users::iterator it;
	for (it = _invited.begin(); it != _invited.end(); it++)
	{
		if (*it == invited)
		{
			_invited.erase(it);
			break;
		}
	}
}

void Channel::removeOperator(Client *op)
{
	t_users::iterator it;
	for (it = _operators.begin(); it != _operators.end(); it++)
	{
		if (*it == op)
		{
			_operators.erase(it);
			return (_bot->removeClient(op));
		}
	}
}

void Channel::broadcast(Client *user, t_string message)
{
	for (size_t i = 0; i < _users.size(); i++)
		if (_users[i]->getFd() != user->getFd())
			sendMessage(_users[i]->getFd(), message);
	for (size_t i = 0; i < _operators.size(); i++)
		if ((_operators[i]->getFd() != user->getFd()))
			sendMessage(_operators[i]->getFd(), message);
}

void Channel::setKey(t_string key) { _key = key; }

void Channel::setTopic(t_string topic) { _topic = topic; }

void Channel::showModes(Client *client)
{
	t_string modes = getModes(this);
	sendMessage(client->getFd(), RPL_CHANNELMODEIS(hostname, client->getNickname(), _name, modes));
	sendMessage(client->getFd(), RPL_CREATIONTIME(hostname, client->getNickname(), _name, getCreationTime()));
	_bot->updateStats(client);
}

bool Channel::changeMode(Client *client, t_string flag, t_string arg, t_string &flags_str, t_string &args_str)
{
	bool res = false;
	if (flag[1] == 'k')
		if (changeKey(client, flag, arg, flags_str, args_str))
			res = true;
	if (flag[1] == 'o')
		if (changeOperator(client, flag, arg, flags_str, args_str))
			res = true;
	if (flag[1] == 'l')
		if (changeLimit(client, flag, arg, flags_str, args_str))
			res = true;
	if (res)
		_bot->updateStats(client);
	return (res);
}

bool Channel::changeMode(Client *client, t_string flag, t_string &flags_str)
{
	bool res = false;
	if (flag[1] == 'l')
		if (resetLimit(client, flags_str))
			res = true;
	if (flag[1] == 'i')
		if (changeInvite(client, flag, flags_str))
			res = true;
	if (flag[1] == 't')
		if (changeTopicRes(client, flag, flags_str))
			res = true;
	if (res)
		_bot->updateStats(client);
	return (res);
}

bool Channel::changeKey(Client *client, t_string flag, t_string arg, t_string &flags_str, t_string &args_str)
{
	if (_key.empty() && flag[0] == '+')
	{
		setKey(arg);
		flags_str += flag;
		args_str += " " + arg;
		logs(_name, client->getNick() + " sets channel keyword to " + arg);
		return (true);
	}
	if (!_key.empty() && flag[0] == '-')
	{
		setKey(t_string());
		flags_str += flag;
		args_str += " " + arg;
		logs(_name, client->getNick() + " removes channel keyword");
		return (true);
	}
	return (false);
}

bool Channel::changeOperator(Client *client, t_string flag, t_string arg, t_string &flags_str, t_string &args_str)
{
	if (flag[0] == '+')
	{
		t_users::iterator it;
		for (it = _operators.begin(); it != _operators.end(); it++)
			if ((*it)->getNick() == arg)
				return (false);
		for (it = _users.begin(); it != _users.end(); it++)
		{
			if ((*it)->getNick() == arg)
			{
				addOperator(*it, false);
				removeUser(*it);
				flags_str += flag;
				args_str += " " + arg;
				logs(_name, client->getNick() + " gives channel operator status to " + arg);
				return (true);
			}
		}
		return (sendMessage(client->getFd(), ERR_USERNOTINCHANNEL(hostname, client->getNickname(), arg, _name)));
	}
	if (flag[0] == '-')
	{
		t_users::iterator it;
		for (it = _users.begin(); it != _users.end(); it++)
			if ((*it)->getNick() == arg)
				return (false);
		for (it = _operators.begin(); it != _operators.end(); it++)
		{
			if ((*it)->getNick() == arg)
			{
				addUser(*it, false);
				removeOperator(*it);
				flags_str += flag;
				args_str += " " + arg;
				logs(_name, client->getNick() + " removes channel operator status to " + arg);
				return (true);
			}
		}
		return (sendMessage(client->getFd(), ERR_USERNOTINCHANNEL(hostname, client->getNickname(), arg, _name)));
	}
	return (false);
}

bool Channel::changeLimit(Client *client, t_string flag, t_string arg, t_string &flags_str, t_string &args_str)
{
	std::stringstream ss(arg);
	if (!isValidLimit(ss.str()))
		return (false);
	size_t new_limit, channel_l;
	ss >> new_limit;
	channel_l = countUsers();
	if (new_limit == std::numeric_limits<size_t>::max())
		return (false);
	if (new_limit < channel_l)
		return (false);
	if (_limit == new_limit)
		return (false);
	std::stringstream ret;
	ret << new_limit;
	_limit = new_limit;
	flags_str += flag;
	args_str += " " + ret.str();
	logs(_name, client->getNick() + " sets channel limit to " + ret.str());
	return (false);
}

bool Channel::resetLimit(Client *client, t_string &flags_str)
{
	if (_limit == std::numeric_limits<size_t>::max())
		return (false);
	_limit = std::numeric_limits<size_t>::max();
	flags_str += "-l";
	logs(_name, client->getNick() + " removes user limit");
	return (true);
}

bool Channel::changeInvite(Client *client, t_string flag, t_string &flags_str)
{
	if (flag == "+i" && _inviteOnly == false)
	{
		_inviteOnly = true;
		flags_str += flag;
		logs(_name, LOG_MODE(client->getNick(), flag, _name));
		return (true);
	}
	if (flag == "-i" && _inviteOnly == true)
	{
		_inviteOnly = false;
		flags_str += flag;
		_invited.clear();
		logs(_name, LOG_MODE(client->getNick(), flag, _name));
		return (true);
	}
	return (false);
}

bool Channel::changeTopicRes(Client *client, t_string flag, t_string &flags_str)
{
	if (flag == "+t" && _topicRest == false)
	{
		_topicRest = true;
		flags_str += flag;
		logs(_name, LOG_MODE(client->getNick(), flag, _name));
		return (true);
	}
	if (flag == "-t" && _topicRest == true)
	{
		_topicRest = false;
		flags_str += flag;
		logs(_name, LOG_MODE(client->getNick(), flag, _name));
		return (true);
	}
	return (false);
}

bool Channel::isInChannel(Client *client)
{
	t_users::iterator it_op, it_usr;
	for (it_op = _operators.begin(); it_op != _operators.end(); it_op++)
		if (*it_op == client)
			return (true);
	for (it_usr = _users.begin(); it_usr != _users.end(); it_usr++)
		if (*it_usr == client)
			return (true);
	return (false);
}

bool Channel::isInChannel(t_string name)
{
	t_users::iterator it_op, it_usr;
	for (it_op = _operators.begin(); it_op != _operators.end(); it_op++)
		if ((*it_op)->getNick() == name)
			return (true);
	for (it_usr = _users.begin(); it_usr != _users.end(); it_usr++)
		if ((*it_usr)->getNick() == name)
			return (true);
	return (false);
}

bool Channel::isOperator(Client *client)
{
	t_users::iterator it;
	for (it = _operators.begin(); it != _operators.end(); it++)
		if (*it == client)
			return (true);
	return (false);
}

bool Channel::isUser(Client *client)
{
	t_users::iterator it;
	for (it = _users.begin(); it != _users.end(); it++)
		if (*it == client)
			return (true);
	return (false);
}

bool Channel::isInvited(Client *client)
{
	t_users::iterator it;
	for (it = _invited.begin(); it != _invited.end(); it++)
		if (*it == client)
			return (true);
	return (false);
}

bool Channel::showTopic(Client *client)
{
	t_string topic = _topic;
	if (topic.empty())
		sendMessage(client->getFd(), RPL_NOTOPIC(hostname, client->getNickname(), _name));
	else
		sendMessage(client->getFd(), RPL_TOPIC(hostname, client->getNickname(), _name, _topic));
	return (_bot->updateStats(client), true);
}

bool Channel::changeTopic(Client *client, t_string new_topic)
{
	if (!isInChannel(client))
		return (sendMessage(client->getFd(), ERR_NOTONCHANNEL(hostname, client->getNickname(), _name)));
	if (_topicRest && !isOperator(client))
		return (sendMessage(client->getFd(), ERR_CHANOPRIVSNEEDED(hostname, client->getNickname(), _name)));
	if (_topic != new_topic)
	{
		logs(_name, LOG_TOPIC(client->getNick(), new_topic));
		_topic = new_topic;
		broadcast(client, RPL_TOPIC2(client->getClient(), _name, _topic));
		sendMessage(client->getFd(), RPL_TOPIC2(client->getClient(), _name, _topic));
		return (_bot->updateStats(client), true);
	}
	return (true);
}

Client *Channel::getBotClient()
{
	for (t_users::iterator it = _operators.begin(); it != _operators.end(); it++)
		if ((*it)->getNick() == _bot->getName())
			return ((*it));
	return (NULL);
}

bool Channel::kickUser(Client *client, Client *kicked, t_args args)
{
	if (!isInChannel(client))
		return (sendMessage(client->getFd(), ERR_NOTONCHANNEL(hostname, client->getNickname(), _name)));
	if (!isOperator(client))
		return (sendMessage(client->getFd(), ERR_CHANOPRIVSNEEDED(hostname, client->getNickname(), _name)));
	if (!isInChannel(kicked))
		return (sendMessage(client->getFd(), ERR_USERNOTINCHANNEL(hostname, client->getNickname(), args[1], _name)));
	removeUser(kicked);
	removeOperator(kicked);
	_bot->updateStats(client);
	t_string reason = (args.size() == 3) ? args[2] : client->getNick();
	logs(_name, LOG_KICK(client->getNick(), args[1], _name, reason));
	broadcast(client, RPL_KICK(client->getClient(), _name, args[1], reason));
	if (client != kicked)
		sendMessage(kicked->getFd(), RPL_KICK(client->getClient(), _name, args[1], reason));
	return (sendMessage(client->getFd(), RPL_KICK(client->getClient(), _name, args[1], reason)));
}
