/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:01:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/26 20:37:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this is not my code, I just push it to study

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#define FATAL "Fatal error"

void ft_error(const char *error)
{
	write(STDERR_FILENO, error, strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

void ft_fail(fd_set *fds, char **msg, int fdmax)
{
	for (int i = 0; i <= fdmax; ++i)
	{
		if (FD_ISSET(i, fds))
		{
			free(msg[i]);
			close(i);
		}
	}
	ft_error(FATAL);
}

void send_message(fd_set *fds, int server, int client, int fdmax, char *msg)
{
	for (int i = 0; i <= fdmax; ++i)
		if (FD_ISSET(i, fds) && i != server && i != client)
			send(i, msg, strlen(msg), 0);
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
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
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
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments");
	socklen_t len;
	int server;
	struct sockaddr_in servaddr, cli;
	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == -1)
		ft_error(FATAL);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));
	if ((bind(server, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0 || \
		listen(server, 10) != 0)
	{
		close(server);
		ft_error(FATAL);
	}
	fd_set fds;
	fd_set events;
	FD_ZERO(&fds);
	FD_SET(server, &fds);
	int fdmax = server;
	int last = -1;
	int ids[FD_SETSIZE] = {-1};
	char *msg[FD_SETSIZE] = {NULL};
	char buf[BUFSIZ];
	while (1)
	{
		events = fds;
		if (select(fdmax + 1, &events, NULL, NULL, NULL) == -1)
			ft_fail(&fds, msg, fdmax);
		for (int i = 0; i <= fdmax; ++i)
		{
			if (FD_ISSET(i, &events))
			{
				if (i == server)
				{
					int client = accept(server, (struct sockaddr *)&cli, &len);
					if (client >= 0)
					{
						FD_SET(client, &fds);
						ids[client] = ++last;
						if (client > fdmax)
							fdmax = client;
						bzero(buf, BUFSIZ);
						sprintf(buf, "server: client %d just arrived\n", last);
						send_message(&fds, server, client, fdmax, buf);
					}
				}
				else
				{
					ssize_t ret;
					bzero(buf, BUFSIZ);
					if ((ret = recv(i, buf, BUFSIZ - 1, 0)) == 0)
					{
						FD_CLR(i, &fds);
						close(i);
						free(msg[i]);
						msg[i] = NULL;
						if (i == fdmax)
							--fdmax;
						bzero(buf, BUFSIZ);
						sprintf(buf, "server: client %d just left\n", ids[i]);
						ids[i] = -1;
						send_message(&fds, server, i, fdmax, buf);
					}
					else if (ret > 0)
					{
						msg[i] = str_join(msg[i], buf);
						if (msg[i] == NULL)
							ft_fail(&fds, msg, fdmax);
						char *line = NULL;
						while ((ret = extract_message(&msg[i], &line)) > 0)
						{
							char *temp = calloc(30, sizeof(char));
							if (temp == NULL)
							{
								free(line);
								ft_fail(&fds, msg, fdmax);
							}
							sprintf(temp, "client %d: ", ids[i]);
							temp = str_join(temp, line);
							free(line);
							if (temp == NULL)
								ft_fail(&fds, msg, fdmax);
							line = NULL;
							send_message(&fds, server, i, fdmax, temp);
							free(temp);
						}
						if (ret == -1)
							ft_fail(&fds, msg, fdmax);
					}
				}
			}
		}
	}
	return (0);
}
