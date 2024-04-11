/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:43:53 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/10 15:34:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"

class Client;

class Channel
{
private:
	int _limit;
	std::string _password, _name, _topic;
	bool _inviteOnly, _topicOprs;
	std::vector<Client *> _clients, _operators;
	std::vector<std::string> _invited;

public:
	Channel(Client *creator, std::string, std::string password = "");
	Channel(const Channel &);
	~Channel();
	std::string getName(void);
	std::string getPassword(void);
	void setPassword(int, std::string);
	int getLimit(void);
	std::vector<Client *>::iterator ft_find_client(std::string);
	std::vector<Client *>::iterator ft_find_operator(int);
	std::vector<Client *>::iterator ft_find_operator(std::string);
	std::vector<std::string>::iterator ft_find_invite(std::string);
	void handleCommands(Client *, std::vector<std::string>, int, std::string);
	void showInfo(int);
	void addClient(Client *);
	void switchMode(int, int);
	void removeClient(Client *);
	void executeKick(int, std::vector<std::string>);
	void executeMode(Client *, std::vector<std::string>);
	void changeProtection(int, std::vector<std::string>);
	void changePrivilege(int, std::string);
	void changeLimit(int, std::vector<std::string>);
	void changeMode(int, int);
	void broadcastMessage(Client *, std::vector<std::string>, int);
	void executeQuit(Client *, std::vector<std::string>);
	void executeInvite(Client *, std::vector<std::string>, int, std::string);
	bool isInvited(std::string);
	void showChannelCommands(int, std::vector<std::string>);
	void executeTopic(Client *, std::vector<std::string>);
	void handleTopicCLient(int, std::vector<std::string>);
	void handleTopicOperator(int, std::vector<std::string>);
	void showChannelTopic(int);
	void sendToAll(const char *);
};

#endif
