/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 19:44:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/05/23 14:01:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_irc.hpp"

t_socket newSocket(const char *arg)
{
	t_socket ret;

	ret.fd = socket(AF_INET, SOCK_STREAM, 0);
	if (ret.fd < 0)
		throw Server::ErrorCreatingSocket();
	int opt = 1;
	if (setsockopt(ret.fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) != 0)
		throw Server::ErrorCreatingSocket();
	if (checkPort(arg) == false)
		throw Server::InvalidPort();
	ret.len = sizeof(ret.addr);
	std::memset(&ret.addr, 0, ret.len);
	ret.addr.sin_family = AF_INET;
	ret.addr.sin_addr.s_addr = htonl(INADDR_ANY);
	ret.addr.sin_port = htons(std::atoi(arg));
	if (bind(ret.fd, (const sockaddr *)&ret.addr, ret.len) != 0)
		throw Server::ErrorBindingSocket();
	if (listen(ret.fd, 100) != 0)
		throw Server::ErrorListenSocket();
	if (gethostname(ret.hostname, sizeof(ret.hostname)) == -1)
		throw Server::ErrorGettingHostname();
	struct hostent *host_entry = gethostbyname(ret.hostname);
	if (host_entry == NULL)
		throw Server::ErrorGettingHostname();
	ret.ip = inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0]));
	if (ret.ip == NULL)
		throw Server::ErrorGettingIP();
	return (ret);
}

t_args ft_split(t_string str)
{
	t_args ret;
	size_t it, start, end;

	it = 0;
	while (str[it] != '\0')
	{
		while (str[it] != '\0' && std::isspace(str[it]) != 0)
			it++;
		start = it;
		while (str[it] != '\0' && std::isspace(str[it]) == 0)
			it++;
		end = it;
		if (end > start)
			ret.push_back(str.substr(start, end - start));
		while (str[it] != '\0' && std::isspace(str[it]) != 0)
			it++;
	}
	return (ret);
}

t_args ft_split(t_string str, char c)
{
	t_args ret;
	size_t it, start, end;

	it = 0;
	while (str[it] != '\0')
	{
		while (str[it] != '\0' && str[it] == c)
			it++;
		start = it;
		while (str[it] != '\0' && str[it] != c)
			it++;
		end = it;
		if (end > start)
			ret.push_back(str.substr(start, end - start));
		while (str[it] != '\0' && str[it] == c)
			it++;
	}
	return (ret);
}

void ft_printargs(t_args args, t_string type)
{
	std::cout << type << ": ";
	for (size_t i = 0; i < args.size(); i++)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << "\"" << args[i] << "\"";
	}
	std::cout << std::endl;
}

void ft_printinput(t_input input)
{
	std::cout << "------ Input -----\n";
	ft_printargs(input.first, "args");
	std::cout << "text: \"" << input.second << "\"";
	std::cout << std::endl
			  << std::endl;
}

size_t ft_findstr(t_string str)
{
	size_t it, start, end;

	it = 0;
	while (str[it] != '\0')
	{
		while (str[it] != '\0' && std::isspace(str[it]) != 0)
			it++;
		start = it;
		while (str[it] != '\0' && std::isspace(str[it]) == 0)
			it++;
		end = it;
		if (end > start)
		{
			t_string tmp = str.substr(start, end - start);
			if (tmp.at(0) != ':')
				continue;
			return (start);
		}
		while (str[it] != '\0' && std::isspace(str[it]) != 0)
			it++;
	}
	return (t_string::npos);
}

t_input getInput(t_string line)
{
	t_input ret;
	size_t len, i;
	bool has_message = false;

	ret.first = ft_split(line);
	len = ret.first.size();
	for (i = 0; i < len; i++)
		if (ret.first[i].find(":") == 0)
			break;
	for (; i < len; i++)
	{
		has_message = true;
		ret.first.pop_back();
	}
	if (has_message == true)
	{
		size_t tmp_pos = ft_findstr(line);
		ret.second = line.substr(tmp_pos + 1, line.size() - (tmp_pos + 1));
	}
	return (ret);
}

bool checkName(t_string name)
{
	if (name.empty())
		return (false);
	if (name[0] == '#')
		return (false);
	size_t i = 0;
	for (i = 0; i < name.size(); i++)
		if (std::isspace(name[i]))
			return (false);
	return (true);
}

bool checkChannel(t_string name)
{
	if (name.empty())
		return (false);
	if (name[0] != '#')
		return (false);
	size_t i = 0;
	for (i = 0; i < name.size(); i++)
		if (std::isspace(name[i]))
			return (false);
	return (true);
}

const t_string getClientSintax(const Client *client)
{
	if (client->getNick().empty())
		return ((const t_string)hostname);
	if (client->getUser().empty())
		return (client->getNick() + "!d@" + hostname);
	return (client->getNick() + "!~" + client->getUser() + "@" + hostname);
}

const t_string getNicknameSintax(const Client *client)
{
	return (client->getNick().empty() ? "*" : client->getNick());
}

const t_string getUsernameSintax(const Client *client)
{
	return ("~" + client->getNick() + "@" + hostname);
}

t_string getTargets(Channel *channel)
{
	t_string targets;
	t_users users = channel->getUsers(), ops = channel->getOperators();
	size_t tmp = 0;
	for (size_t i = 0; i < users.size(); i++)
	{
		if (tmp > 0)
			targets += " ";
		targets += users[i]->getNick();
		tmp++;
	}
	for (size_t i = 0; i < ops.size(); i++)
	{
		if (tmp > 0)
			targets += " ";
		targets += "@" + ops[i]->getNick();
		tmp++;
	}
	return (targets);
}

bool sendMessage(int fd, t_string message)
{
	const char *buf = message.c_str();
	send(fd, buf, std::strlen(buf), MSG_DONTWAIT);
	return (true);
}

bool welcomeMessage(Client *client)
{
	t_string welcome;
	welcome += "███████╗████████╗    ██╗██████╗  ██████╗\n";
	welcome += "██╔════╝╚══██╔══╝    ██║██╔══██╗██╔════╝\n";
	welcome += "█████╗     ██║       ██║██████╔╝██║\n";
	welcome += "██╔══╝     ██║       ██║██╔══██╗██║\n";
	welcome += "██║        ██║       ██║██║  ██║╚██████╗\n";
	welcome += "╚═╝        ╚═╝       ╚═╝╚═╝  ╚═╝ ╚═════╝\n";
	logs("server", getInfoClient(client) + " " + LOG_AUTHENTICATED);
	return (sendMessage(client->getFd(), welcome));
}

void welcomeMessage(void)
{
	std::cout << "\t███████╗████████╗    ██╗██████╗  ██████╗" << std::endl;
	std::cout << "\t██╔════╝╚══██╔══╝    ██║██╔══██╗██╔════╝" << std::endl;
	std::cout << "\t█████╗     ██║       ██║██████╔╝██║" << std::endl;
	std::cout << "\t██╔══╝     ██║       ██║██╔══██╗██║" << std::endl;
	std::cout << "\t██║        ██║       ██║██║  ██║╚██████╗" << std::endl;
	std::cout << "\t╚═╝        ╚═╝       ╚═╝╚═╝  ╚═╝ ╚═════╝" << std::endl;
}

t_string ft_getwordpos(t_string line, size_t pos)
{
	size_t it, start, end;
	unsigned int words = 0;

	it = 0;
	while (line[it] != '\0')
	{
		while (line[it] != '\0' && std::isspace(line[it]) != 0)
			it++;
		start = it;
		while (line[it] != '\0' && std::isspace(line[it]) == 0)
			it++;
		end = it;
		if (end > start)
		{
			if (words == pos)
				return (line.substr(start, end - start));
			words++;
		}
		while (line[it] != '\0' && std::isspace(line[it]) != 0)
			it++;
	}
	return (t_string());
}

t_args getArgsPro(t_input input, size_t start_pos)
{
	t_args ret;
	size_t i;

	for (i = start_pos; i < input.first.size(); i++)
		ret.push_back(input.first[i]);
	if (!input.second.empty())
		ret.push_back(input.second);
	return (ret);
}

t_args getModeFlags(t_string mode)
{
	t_args ret;
	size_t it = 0;
	while (mode[it] != '\0')
	{
		size_t start = it;
		while (mode[it] != '\0' && (mode[it] == '+' || mode[it] == '-'))
			it++;
		while (mode[it] != '\0' && !(mode[it] == '+' || mode[it] == '-'))
			it++;
		size_t end = it;
		t_string tmp = "+" + mode.substr(start, end - start);
		if (tmp[0] != '+' && tmp[0] != '-')
			continue;
		int signal = 1;
		size_t i = 0;
		while (tmp[i] != '\0' && (tmp[i] == '+' || tmp[i] == '-'))
		{
			if (tmp[i] == '-')
				signal = -signal;
			i++;
		}
		char signal_char = (signal == 1 ? '+' : '-');
		while (tmp[i] != '\0' && !(tmp[i] == '+' || tmp[i] == '-'))
		{
			t_string tmp_str;
			tmp_str.append(1, signal_char);
			tmp_str.append(1, tmp[i]);
			ret.push_back(tmp_str);
			i++;
		}
	}
	return (ret);
}

t_string getModes(Channel *channel)
{
	t_string flags = "+";
	t_string values;
	if (channel->getTopicFlag())
		flags += "t";
	if (channel->getInviteFlag())
		flags += "i";
	if (channel->getLimit() != std::numeric_limits<size_t>::max())
	{
		flags += "l";
		std::stringstream ss;
		ss << channel->getLimit();
		values += " " + ss.str();
	}
	if (!channel->getKey().empty())
	{
		flags += "k";
		std::stringstream ss;
		ss << channel->getKey();
		values += " " + ss.str();
	}
	return (flags + values);
}

t_args copyFromPos(t_args args, size_t pos)
{
	t_args ret;

	for (size_t i = pos; i < args.size(); i++)
		ret.push_back(args[i]);
	return (ret);
}

bool ft_findarg(t_args args, t_string str)
{
	t_args ret;

	for (size_t i = 0; i < args.size(); i++)
		if (args[i][1] == str[1])
			return (true);
	return (false);
}

t_string getInfoClient(Client *client)
{
	std::stringstream ss;
	ss << client->getFd();
	if (client->getClient() == hostname)
		return (INFO_SOCKET(ss.str()));
	return (client->getClient());
}

void logs(t_string place, t_string message) { std::cout << place << ": " << message << std::endl; }

bool isValidLimit(t_string limit)
{
	int sign = 1;
	size_t i = 0;
	while (limit[i] != '\0' && isspace(limit[i]))
		i++;
	if (limit[i] == '+' || limit[i] == '-')
		if (limit[i++] == '-')
			sign = -1;
	return (sign > 0 && limit[i] != '\0' && isdigit(limit[i]));
}

bool checkPort(const char *arg)
{
	int tmp = 0, sign = 1;
	while (*arg != '\0' && std::isspace(*arg))
		arg++;
	if (*arg == '+' || *arg == '-')
		if (*arg++ == '-')
			sign = -1;
	while (*arg != '\0' && std::isdigit(*arg))
	{
		tmp = tmp * 10 + *arg++ - '0';
		if (tmp * sign <= 0 || tmp * sign > 65535)
			return (false);
	}
	if (tmp * sign <= 0 || tmp * sign > 65535)
		return (false);
	return (true);
}
