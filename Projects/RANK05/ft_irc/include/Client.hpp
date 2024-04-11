/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acanelas <acanelas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 10:53:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/05 19:13:43 by acanelas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "Channel.hpp"

class Channel;

class Client 
{
private:
	int _fd;
	std::string _name;
	std::string _password;
	bool _isLogged;
	Channel *_channel;
public:
	Client(int, std::string, std::string);
	Client(const Client &);
	Client &operator=(const Client &);
	~Client();
	int getFd(void);
	std::string getPassword(void);
	void setFd(int);
	void logout();
	void login();
	std::string getName(void);
	Channel *getChannel(void);
	void setChannel(Channel *channel);
	bool isLogged(void);
	void showInfo(int);
};

#endif
