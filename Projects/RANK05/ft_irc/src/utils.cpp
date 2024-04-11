/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 08:38:31 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/10 16:09:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_irc.hpp"

std::string ft_strtrim(std::string str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	size_t last = str.find_last_not_of(" \t\n\r");
	if (first == std::string::npos)
		return ("");
	return (str.substr(first, last - first + 1));
}

int isValidName(std::string line)
{
	if (line.size() < 3 || line.size() > 20)
		return (0);
	for (size_t i = 0; i < line.size(); i++)
		if (isspace(line[i]) || (!isalnum(line[i]) &&
								 line[i] != '.' && line[i] != '-' && line[i] != '_'))
			return (0);
	for (size_t i = 0; i < line.size() - 1; i++)
		if (!isalnum(line[i]) && !isalnum(line[i + 1]))
			return (0);
	return (isalpha(line[0]) && isalnum(line[line.size() - 1]));
}

int isValidChannelName(std::string line)
{
	if (line.size() < 3)
		return (0);
	for (size_t i = 0; i < line.size(); i++)
		if (isspace(line[i]) || (!isalnum(line[i]) &&
								 line[i] != '_'))
			return (0);
	for (size_t i = 0; i < line.size() - 1; i++)
		if (!isalnum(line[i]) && !isalnum(line[i + 1]))
			return (0);
	return (line[0] != '_' && line[line.size()] != '_');
}

bool checkPassword(std::string password)
{
	std::vector<bool> steps;
	steps.push_back(false);
	steps.push_back(false);
	steps.push_back(false);
	steps.push_back(false);
	steps.push_back(false);
	for (size_t i = 0; i < password.size(); i++)
	{
		if (isspace(password[i]))
			return (false);
		if (isupper(password[i]))
			steps[0] = true;
		else if (islower(password[i]))
			steps[1] = true;
		else if (isdigit(password[i]))
			steps[2] = true;
		else
			steps[3] = true;
	}
	steps[4] = (password.size() >= 8 && password.size() <= 32);
	for (size_t i = 0; i < steps.size(); i++)
		if (!steps[i])
			return (false);
	return (true);
}

bool processPassword(int fd, std::string password)
{
	if (!checkPassword(password))
	{
		sendToClient(fd, INVALID_PWD, true);
		sendToClient(fd, LOGIN_MSG, false);
		return (false);
	}
	return (true);
}

bool processUserName(int fd, std::string line)
{
	int result = isValidName(line);
	if (result == 1)
		return (true);
	sendToClient(fd, INVALID_USER, true);
	sendToClient(fd, LOGIN_MSG, false);
	return (false);
}

std::vector<std::string> splitString(const std::string &str)
{
	std::istringstream iss(str);
	std::vector<std::string> tokens;
	std::string token;
	while (iss >> token)
		if (!token.empty())
			tokens.push_back(token);
	return tokens;
}

void sendMessage(Client *sender, Client *receiver, std::vector<std::string> args, int mode)
{
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	const char *color = (mode == 0) ? MAG : CYN;
	size_t i = (mode == 0) ? 2 : 0;
	if (sender->getFd() == receiver->getFd())
		sendToClient(sender->getFd(), "\033[1A", false);
	sprintf(buf, "%s\033[2K \r@%s:", color, sender->getName().c_str());
	sendToClient(receiver->getFd(), buf, false);
	bzero(&buf, BUFSIZ);
	std::string message = "";
	for (; i < args.size(); i++)
		message += " " + args[i];
	message += "\n";
	sprintf(buf, "%s" COLOR_RESET, message.c_str());
	sendToClient(receiver->getFd(), buf, false);
	if (sender->getFd() != receiver->getFd())
	{
		if (receiver->getChannel() == NULL)
			sendToClient(receiver->getFd(), PROMPT, false);
		else
		{
			bzero(&buf, BUFSIZ);
			sprintf(buf, CYN "[%s]> " COLOR_RESET, receiver->getChannel()->getName().c_str());
			sendToClient(receiver->getFd(), buf, false);
		}
	}
}

void sendInfo(Client *sender, Client *receiver, std::vector<std::string> args)
{
	sendToClient(receiver->getFd(), "\033[2k \r", false);
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	sprintf(buf, "The topic was changed to '%s'\n" COLOR_RESET, args[0].c_str());
	sendToClient(receiver->getFd(), buf, false);
	if (sender->getFd() != receiver->getFd())
	{
		if (receiver->getChannel() == NULL)
			sendToClient(receiver->getFd(), PROMPT, false);
		else
		{
			bzero(&buf, BUFSIZ);
			sprintf(buf, CYN "[%s]> " COLOR_RESET, receiver->getChannel()->getName().c_str());
			sendToClient(receiver->getFd(), buf, false);
		}
	}
}

void sendToClient(int fd, const char *msg, bool isError)
{
	char buf[BUFSIZ];
	bzero(&buf, BUFSIZ);
	if (isError)
		sprintf(buf, "[ERROR]: %s\n", msg);
	else
		sprintf(buf, "%s", msg);
	send(fd, buf, strlen(buf), MSG_DONTWAIT);
}
