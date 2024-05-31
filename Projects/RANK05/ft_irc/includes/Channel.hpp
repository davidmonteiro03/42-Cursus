/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:47:33 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 17:36:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP

class Channel
{
private:
	t_string _name, _key, _topic;
	t_users _users, _operators, _invited;
	bool _inviteOnly, _topicRest;
	size_t _limit;
	time_t _creationTime;
	Bot *_bot;

public:
	Channel(t_string);
	~Channel();
	t_string getName(void) const;
	t_string getKey(void) const;
	t_string getTopic(void) const;
	t_users getUsers(void) const;
	t_users getOperators(void) const;
	bool getInviteFlag(void) const;
	bool getTopicFlag(void) const;
	size_t getLimit(void) const;
	void addUser(Client *, bool);
	void addInvited(Client *, Client *);
	void removeInvited(Client *);
	void addOperator(Client *, bool);
	void removeUser(Client *);
	void removeOperator(Client *);
	void broadcast(Client *, t_string);
	void setKey(t_string);
	void setTopic(t_string);
	void showModes(Client *);
	bool changeMode(Client *, t_string, t_string, t_string &, t_string &);
	bool changeMode(Client *, t_string, t_string &);
	bool changeKey(Client *, t_string, t_string, t_string &, t_string &);
	bool changeOperator(Client *, t_string, t_string, t_string &, t_string &);
	bool changeLimit(Client *, t_string, t_string, t_string &, t_string &);
	bool changeInvite(Client *, t_string, t_string &);
	bool changeTopicRes(Client *, t_string, t_string &);
	bool resetLimit(Client *, t_string &);
	bool isInChannel(Client *);
	bool isInChannel(t_string);
	bool isOperator(Client *);
	bool isUser(Client *);
	bool isInvited(Client *);
	size_t countUsers();
	void addBot(Bot *);
	bool showTopic(Client *);
	bool changeTopic(Client *, t_string);
	Client *getBotClient();
	bool kickUser(Client *, Client *, t_args);
	t_string getCreationTime(void) const;
};

#endif
