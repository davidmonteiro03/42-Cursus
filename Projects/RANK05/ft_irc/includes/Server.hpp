/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:31:28 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 11:31:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

class Server
{
private:
	t_fds _fds;
	t_socket _socket;
	int _fdmax, _port;
	t_string _password;
	t_msgs _msgs;
	t_clients _clients;
	t_channels _channels;
	bool connect(void);
	bool handle(int);
	bool disconnect(int, t_string);
	bool parseLine(int, t_string);
	bool executePass(int, t_input, t_string);
	bool executeNick(int, t_input, t_string);
	bool executeUser(int, t_input, t_string);
	bool executeJoin(int, t_input, t_string);
	bool executeMode(int, t_input, t_string);
	bool executeTopic(int, t_input, t_string);
	bool executeInvite(int, t_input, t_string);
	bool executeKick(int, t_input, t_string);
	bool executeWho(int, t_input, t_string);
	bool executePart(int, t_input, t_string);
	bool executePrivMsg(int, t_input, t_string);
	bool executeQuit(int, t_input);
	bool joinClientChannel(Client *, t_string, t_string);
	bool joinNewChannel(Client *, t_string);
	bool joinExistingChannel(Client *, Channel *, t_string);
	void partClientChannel(Client *, t_string, t_string);
	bool showChannelModes(Client *, t_string);
	bool changeChannelModes(Client *, t_string, t_args, t_args);
	bool showTopicChannel(Client *, Channel *);
	bool changeTopicChannel(Client *, Channel *, t_string);
	bool kickUser(Client *, Channel *, t_args);
	bool sendToUser(Client *, t_string, t_string);
	bool sendToChannel(Client *, t_string, t_string);
	Client *findClient(t_string);
	void removeEmptyChannels(void);

public:
	Server(int, char **);
	~Server();
	void execute(void);
	void getInfo(void) const;
	class ErrorUsage : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class InvalidPort : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ErrorCreatingSocket : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ErrorBindingSocket : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ErrorListenSocket : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ErrorGettingHostname : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class ErrorGettingIP : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif
