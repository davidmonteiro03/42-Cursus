/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 13:55:00 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/27 17:27:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern "C"
{
	#include <unistd.h>
	#include <strings.h>
	#include <sys/socket.h>
	#include <sys/select.h>
	#include <netdb.h>
	#include <arpa/inet.h>
}

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>

#define FATAL "Fatal error"
#define PASSWORD_REQUEST "Type server password: "
#define USERNAME_REQUEST "Choose your username: "
#define ERROR_PASSWORD "Wrong password! Try again...\n"
#define ERROR_USERNAME "Invalid username! Try again...\n"
#define COMMAND "Command > "

void ft_error(const char *error)
{
	write(STDERR_FILENO, error, strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = (char *)calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = (char *)malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_message(fd_set *fds, int client, int server, bool check[FD_SETSIZE][2], \
	int nfds, char *msg, bool all_people)
{
	if (!all_people)
	{
		for (int i = 0; i <= nfds; ++i)
			if (FD_ISSET(i, fds) && check[i][0] && check[i][1] && i != server && i != client)
				send(i, msg, strlen(msg), 0);
	}
	else
	{
		for (int i = 0; i <= nfds; ++i)
			if (FD_ISSET(i, fds) && check[i][0] && check[i][1] && i != server)
				send(i, msg, strlen(msg), 0);
	}
}

void ft_fail(fd_set *fds, char **msg, int nfds)
{
	for (int i = 0; i <= nfds; ++i)
	{
		if (FD_ISSET(i, fds))
		{
			free(msg[i]);
			close(i);
		}
	}
	ft_error(FATAL);
}

bool check_username(std::string username, std::string users[FD_SETSIZE], int nfds)
{
	if (username.size() < 3 || username.size() > 20)
		return (false);
	for (size_t i = 0; i < username.size(); ++i)
		if (isspace(username[i]))
			return (false);
	for (int i = 0; i <= nfds; ++i)
		if (username == users[i])
			return (false);
	return (true);
}

int main(void)
{
	int server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == -1)
		return (EXIT_FAILURE);
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(8080);
	if (bind(server, (const sockaddr*)&servaddr, sizeof(servaddr)) == -1 || \
		listen(server, 10) == -1)
	{
		close(server);
		ft_error(FATAL);
	}
	fd_set fds, events;
	struct sockaddr_in cli;
	socklen_t len;
	FD_ZERO(&fds);
	FD_SET(server, &fds);
	int nfds = server;
	char buf[BUFSIZ];
	char *msg[FD_SETSIZE] = {NULL};
	bool check[FD_SETSIZE][2] = {{false, false}};
	std::string users[FD_SETSIZE] = {""};
	while (1)
	{
		events = fds;
		if (select(nfds + 1, &events, NULL, NULL, NULL) == -1)
			ft_fail(&fds, msg, nfds);
		for (int i = 0; i <= nfds; i++)
		{
			if (FD_ISSET(i, &events))
			{
				if (i == server)
				{
					int client = accept(server, (struct sockaddr *)&cli, &len);
					if (client >= 0)
					{
						FD_SET(client, &fds);
						if (client > nfds)
							nfds = client;
						send(client, PASSWORD_REQUEST, strlen(PASSWORD_REQUEST), 0);
					}
				}
				else
				{
					bzero(buf, BUFSIZ);
					ssize_t ret = recv(i, buf, BUFSIZ - 1, 0);
					if (ret == 0)
					{
						FD_CLR(i, &fds);
						close(i);
						free(msg[i]);
						msg[i] = NULL;
						check[i][0] = false;
						check[i][1] = false;
						users[i] = "";
						if (i == nfds)
							--nfds;
					}
					else if (ret > 0)
					{
						msg[i] = str_join(msg[i], buf);
						if (msg[i] == 0)
							ft_fail(&fds, msg, nfds);
						char *line = NULL;
						ret = extract_message(&msg[i], &line);
						while (ret > 0)
						{
							std::string message = line;
							message.erase(message.find_last_not_of(" \n\r\t") + 1);
							if (check[i][0] == false)
							{
								if (message != "password")
								{
									send(i, ERROR_PASSWORD, strlen(ERROR_PASSWORD), 0);
									send(i, PASSWORD_REQUEST, strlen(PASSWORD_REQUEST), 0);
								}
								else
								{
									check[i][0] = true;
									send(i, USERNAME_REQUEST, strlen(USERNAME_REQUEST), 0);
								}
							}
							else if (check[i][1] == false)
							{
								if (!check_username(message, users, nfds))
								{
									send(i, ERROR_USERNAME, strlen(ERROR_USERNAME), 0);
									send(i, USERNAME_REQUEST, strlen(USERNAME_REQUEST), 0);
								}
								else
								{
									check[i][1] = true;
									users[i] = message;
									char *temp = (char *)calloc(BUFSIZ, sizeof(char));
									if (temp == NULL)
									{
										free(line);
										ft_fail(&fds, msg, nfds);
									}
									bzero(temp, BUFSIZ);
									sprintf(temp, "Welcome to the server, %s!\n", (char *)users[i].c_str());
									send(i, temp, strlen(temp), 0);
									free(temp);
									send(i, COMMAND, strlen(COMMAND), 0);
								}
							}
							else
							{
								char *temp = (char *)calloc(BUFSIZ, sizeof(char));
								if (temp == NULL)
								{
									free(line);
									ft_fail(&fds, msg, nfds);
								}
								bzero(temp, BUFSIZ);
								sprintf(temp, "\n%s: ", (char *)users[i].c_str());
								temp = str_join(temp, line);
								if (temp == NULL)
									ft_fail(&fds, msg, nfds);
								if (message.size() > 0)
								{
									send_message(&fds, i, server, check, nfds, temp, false);
									send_message(&fds, i, server, check, nfds, (char *)COMMAND, true);
								}
								else
									send(i, COMMAND, strlen(COMMAND), 0);
								free(temp);
							}
							message.clear();
							free(line);
							line = NULL;
							ret = extract_message(&msg[i], &line);
						}
					}
				}
			}
		}
	}
	return (EXIT_SUCCESS);
}
