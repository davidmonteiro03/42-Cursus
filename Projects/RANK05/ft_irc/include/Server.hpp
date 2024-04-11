/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:25:40 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/10 14:23:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "Channel.hpp"
#include "Client.hpp"

class Channel;
class Client;

class Server
{
private:
	std::pair<int, std::string> _info;
	int _server;
	struct sockaddr_in _servaddr;
	fd_set _fds, _events;
	int _nfds;
	bool _status[FD_SETSIZE];
	bool _session[FD_SETSIZE];
	std::vector<Client *> _clients;
	std::vector<Channel *> _channels;

public:
	Server(int, char **);
	Server(const Server &);
	Server &operator=(const Server &);
	~Server();
	std::vector<Client *>::iterator ft_find_client(int);
	std::vector<Client *>::iterator ft_find_client(std::string);
	std::vector<Channel *>::iterator ft_find_channel(std::string);
	void welcomeUser(int, std::string, std::string, bool);
	void createServer(void);
	void listenInput(void);
	void acceptSocket(void);
	void getInput(int);
	void handleCommands(int, std::string);
	void handleServerCommands(int fd, std::vector<std::string> args);
	void parseMessage(int, std::string);
	void closeServer(int);
	void showServerCommands(int);
	void showUsers(int);
	void showChannels(int);
	void executeExit(int, int);
	void executeShow(int, std::vector<std::string>);
	void executeJoin(int, std::vector<std::string>);
	void executeCreate(int, std::vector<std::string>);
	void executePrivate(int, std::vector<std::string>);
	void clientLeft(int);
	void createAccount(int, std::string, std::string);
	void recoverAccount(int, std::string, std::string);
	void searchUser(int, int &, std::vector<std::string>);
	void createReferenceClient(void);
	void executeHelp(int fd, std::vector<std::string> args);
	class Usage : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ServerError : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
