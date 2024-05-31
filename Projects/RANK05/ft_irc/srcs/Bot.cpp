/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:33:53 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/24 11:49:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

Bot::Bot(t_string name, Channel *channel)
{
	_name = name + "_BOT";
	_channel = channel;
	_levels.push_back("ROOKIE");
	_levels.push_back("APPRENTICE");
	_levels.push_back("NOVICE");
	_levels.push_back("EXPERT");
}

Bot::~Bot() {}

t_string Bot::getName() { return _name; }

void Bot::addStats(Client *client)
{
	_stats.push_back(std::make_pair(client, -1));
	t_string message = "WELCOME TO " + _channel->getName() + "!";
	sendMessage(client->getFd(), RPL_MSG(_name + "!d@" + hostname, client->getNickname(), message));
}

void Bot::updateStats(Client *client)
{
	for (size_t i = 0; i < _stats.size(); i++)
	{
		if (_stats[i].first == client)
		{
			if (++_stats[i].second % 10 == 0)
				checkStats(client, _stats[i].first->getNick(), true);
		}
	}
}

size_t Bot::getClientLevel(t_string nick)
{
	for (size_t i = 0; i < _stats.size(); i++)
		if (_stats[i].first->getNick() == nick)
			return (_stats[i].second / 10);
	return (-1);
}

void Bot::checkStats(Client *client, t_string nick, bool mode)
{
	t_string message;
	size_t lvl = getClientLevel(nick);
	if (lvl > _levels.size() - 1)
		return;
	Client *bot_client = _channel->getBotClient();
	if (mode == true)
	{
		message = nick + " HAS LEVELED UP! (" + _levels[lvl] + ")";
		_channel->broadcast(bot_client, RPL_MSG(bot_client->getClient(), _channel->getName(), message));
	}
	message = "🎉 CONGRATS! YOU ARE NOW A " + t_string(_levels[lvl]) + "! 🎉";
	sendMessage(client->getFd(), RPL_MSG(bot_client->getClient(), nick, message));
}

void Bot::removeClient(Client *client)
{
	t_stats::iterator it;
	for (it = _stats.begin(); it != _stats.end(); it++)
		if (it->first == client)
			return (_stats.erase(it), void());
}
