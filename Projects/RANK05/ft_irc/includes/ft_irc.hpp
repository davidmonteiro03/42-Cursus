/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_irc.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:23:39 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 22:09:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IRC_HPP
#define FT_IRC_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <vector>
#include <map>
#include <limits>
#include <stdexcept>
#include <ctime>
#include <iomanip>

extern "C"
{
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
}

enum
{
	PASS,
	NICK,
	USER
};

typedef struct s_socket
{
	int fd;
	struct sockaddr_in addr;
	socklen_t len;
	char hostname[256], *ip;
} t_socket;

typedef struct s_fds
{
	fd_set all, read, write;
} t_fds;

class Server;
class Client;
class Channel;
class Bot;

typedef std::string t_string;
typedef std::vector<t_string> t_args;
typedef std::pair<t_args, t_string> t_input;
typedef std::map<int, Client *> t_clients;
typedef std::map<int, t_string> t_msgs;
typedef std::vector<Channel *> t_channels;
typedef std::vector<Client *> t_users;
typedef std::vector<std::pair<Client *, int> > t_stats;

#include "Server.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "Bot.hpp"

#define RPL_CHANNELMODEIS(hostname, nickname, channel, modestring) \
	":" + t_string(hostname) + " 324 " + t_string(nickname) + " " + t_string(channel) + " " + t_string(modestring) + "\r\n"

#define RPL_CREATIONTIME(hostname, nickname, channel, creationtime) \
	":" + t_string(hostname) + " 329 " + t_string(nickname) + " " + t_string(channel) + " " + t_string(creationtime) + "\r\n"

#define RPL_NOTOPIC(hostname, nickname, channel) \
	":" + t_string(hostname) + " 331 " + t_string(nickname) + " " + t_string(channel) + " :No topic is set\r\n"

#define RPL_TOPIC(hostname, nickname, channel, topic) \
	":" + t_string(hostname) + " 332 " + t_string(nickname) + " " + t_string(channel) + " :" + t_string(topic) + "\r\n"

#define RPL_NAMREPLY(hostname, nickname, symbol, channel, users) \
	":" + t_string(hostname) + " 353 " + t_string(nickname) + " " + t_string(symbol) + " " + t_string(channel) + " :" + t_string(users) + "\r\n"

#define RPL_ENDOFNAMES(hostname, nickname, channel) \
	":" + t_string(hostname) + " 366 " + t_string(nickname) + " " + t_string(channel) + " :End of /NAMES list.\r\n"

#define RPL_INVITING(hostname, channel, nickname) \
	":" + t_string(hostname) + " 341 " + t_string(channel) + " " + t_string(nickname) + " " + t_string(channel) + "\r\n"

#define ERR_NOSUCHNICK(hostname, nickname, argument) \
	":" + t_string(hostname) + " 401 " + t_string(nickname) + " " + t_string(argument) + " :No such nick\r\n"

#define ERR_NOSUCHCHANNEL(hostname, nickname, channel) \
	":" + t_string(hostname) + " 403 " + t_string(nickname) + " " + t_string(channel) + " :No such channel\r\n"

#define ERR_UNKNOWNCOMMAND(hostname, nickname, command) \
	":" + t_string(hostname) + " 421 " + t_string(nickname) + " " + t_string(command) + " :Unknown command\r\n"

#define ERR_ERRONEUSNICKNAME(hostname, nickname, argument) \
	":" + t_string(hostname) + " 432 " + t_string(nickname) + " " + t_string(argument) + " :Erroneus nickname\r\n"

#define ERR_NICKNAMEINUSE(hostname, nickname, argument) \
	":" + t_string(hostname) + " 433 " + t_string(nickname) + " " + t_string(argument) + " :Nickname is already in use\r\n"

#define ERR_USERNOTINCHANNEL(hostname, nickname, argument, channel) \
	":" + t_string(hostname) + " 441 " + t_string(nickname) + " " + t_string(argument) + " " + t_string(channel) + " :They aren't on that channel\r\n"

#define ERR_NOTONCHANNEL(hostname, nickname, channel) \
	":" + t_string(hostname) + " 442 " + t_string(nickname) + " " + t_string(channel) + " :You're not on that channel\r\n"

#define ERR_USERONCHANNEL(hostname, nickname, channel) \
	":" + t_string(hostname) + " 443 " + t_string(nickname) + " " + t_string(channel) + " :You're already on that channel\r\n"

#define ERR_NOTREGISTERED(hostname, nickname) \
	":" + t_string(hostname) + " 451 " + t_string(nickname) + " :You have not registered\r\n"

#define ERR_NEEDMOREPARAMS(hostname, nickname, command) \
	":" + t_string(hostname) + " 461 " + t_string(nickname) + " " + t_string(command) + " :Not enough parameters\r\n"

#define ERR_ALREADYREGISTERED(hostname, nickname) \
	":" + t_string(hostname) + " 462 " + t_string(nickname) + " :You may not reregister\r\n"

#define ERR_PASSWDMISMATCH(hostname, nickname, password) \
	":" + t_string(hostname) + " 464 " + t_string(nickname) + " " + t_string(password) + " :Password incorrect\r\n"

#define ERR_CHANNELISFULL(hostname, nickname, channel) \
	":" + t_string(hostname) + " 471 " + t_string(nickname) + " " + t_string(channel) + " :Cannot join channel (+l)\r\n"

#define ERR_INVITEONLYCHAN(hostname, nickname, channel) \
	":" + t_string(hostname) + " 473 " + t_string(nickname) + " " + t_string(channel) + " :Cannot join channel (+i)\r\n"

#define ERR_BADCHANNELKEY(hostname, nickname, channel) \
	":" + t_string(hostname) + " 475 " + t_string(nickname) + " " + t_string(channel) + " :Cannot join channel (+k)\r\n"

#define ERR_INVALIDCHANNELNAME(hostname, nickname, argument) \
	":" + t_string(hostname) + " 476 " + t_string(nickname) + " " + t_string(argument) + " :Invalid channel name\r\n"

#define ERR_CHANOPRIVSNEEDED(hostname, nickname, channel) \
	":" + t_string(hostname) + " 482 " + t_string(nickname) + " " + t_string(channel) + " :You're not channel operator\r\n"

#define RPL_NICKNAME(client, nickname) \
	":" + t_string(client) + " NICK " + t_string(nickname) + "\r\n"

#define RPL_TOPIC2(client, channel, topic) \
	":" + t_string(client) + " TOPIC " + t_string(channel) + " :" + t_string(topic) + "\r\n"

#define RPL_JOIN(client, channel) \
	":" + t_string(client) + " JOIN " + t_string(channel) + "\r\n"

#define RPL_JOIN2(client, channel) \
	":" + t_string(client) + " JOIN :" + t_string(channel) + "\r\n"

#define RPL_MODE(client, channel, flags, args) \
	":" + t_string(client) + " MODE " + t_string(channel) + " " + t_string(flags) + t_string(args) + "\r\n"

#define RPL_PART1(client, channel) \
	":" + t_string(client) + " PART " + t_string(channel) + "\r\n"

#define RPL_PART2(client, channel, reason) \
	":" + t_string(client) + " PART " + t_string(channel) + " :" + t_string(reason) + "\r\n"

#define RPL_KICK(client, channel, user, reason) \
	":" + t_string(client) + " KICK " + t_string(channel) + " " + t_string(user) + " :" + t_string(reason) + "\r\n"

#define RPL_QUIT1(client) \
	":" + t_string(client) + " QUIT\r\n"

#define RPL_QUIT2(client, reason) \
	":" + t_string(client) + " QUIT :" + t_string(reason) + "\r\n"

#define RPL_INVITE(client, channel, guest) \
	":" + t_string(client) + " INVITE " + t_string(guest) + " " + t_string(channel) + "\r\n"

#define RPL_MSG(client, target, message) \
	":" + t_string(client) + " PRIVMSG " + t_string(target) + " :" + t_string(message) + "\r\n"

#define RPL_NOTICE(client, target, message) \
	":" + t_string(client) + " NOTICE " + t_string(target) + " :" + t_string(message) + "\r\n"

#define INFO_SOCKET(fd) \
	"client on socket " + t_string(fd)

#define LOG_CONNECTED "has connected"
#define LOG_DISCONNECTED "has disconnected"
#define LOG_AUTHENTICATED "has authenticated"
#define LOG_SHUTDOWN "shutdown"

#define LOG_NICK(nickname) \
	"has changed nickname to '" + t_string(nickname) + "'"

#define LOG_USER(username, realname) \
	"has registered username '" + t_string(username) + "' (knowed by '" + t_string(realname) + "')"

#define LOG_JOIN(channel) \
	"is now talking on " + t_string(channel)

#define LOG_JOIN2(nickname, username) \
	t_string(nickname) + " (" + t_string(username) + ") has joined"

#define LOG_MODE(nickname, mode, channel) \
	t_string(nickname) + " sets mode " + t_string(mode) + " on " + t_string(channel)

#define LOG_TOPIC(nickname, topic) \
	t_string(nickname) + " has changed the topic to: " + t_string(topic)

#define LOG_KICK(killer, victim, channel, reason) \
	t_string(killer) + " has kicked " + t_string(victim) + " from " + t_string(channel) + " (" + t_string(reason) + ")"

#define LOG_INVITE(inviter, invited, channel) \
	t_string(inviter) + " invited " + t_string(invited) + " to " + t_string(channel)

#define LOG_PART1(nickname, username) \
	t_string(nickname) + " (" + t_string(username) + ") has left"

#define LOG_PART2(nickname, username, reason) \
	t_string(nickname) + " (" + t_string(username) + ") has left (" + t_string(reason) + ")"

#define LOG_PRIVMSG(sender, reciever, message) \
	t_string(sender) + " sent '" + t_string(message) + "' to " + t_string(reciever)

#define MODE_CHARSET "itkol"

t_socket newSocket(const char *);
t_args ft_split(t_string);
t_args ft_split(t_string, char);
void ft_printargs(t_args, t_string);
void ft_printinput(t_input);
t_input getInput(t_string);
bool checkName(t_string);
bool checkChannel(t_string);
const t_string getClientSintax(const Client *);
const t_string getNicknameSintax(const Client *);
const t_string getUsernameSintax(const Client *);
t_string getTargets(Channel *);
bool sendMessage(int, t_string);
bool welcomeMessage(Client *);
void welcomeMessage(void);
t_string ft_getwordpos(t_string, size_t);
t_args getArgsPro(t_input, size_t);
t_args getModeFlags(t_string);
t_string getModes(Channel *);
t_args copyFromPos(t_args, size_t);
bool ft_findarg(t_args, t_string);
t_string getInfoClient(Client *client);
void logs(t_string, t_string);
bool isValidLimit(t_string);
bool checkPort(const char *);

extern char hostname[256], *ip;

#endif
