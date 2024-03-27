/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 09:11:43 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/27 13:24:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netdb.h>

#define FATAL "Fatal error"

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

void send_message(fd_set *fds, int server, int client, int nfds, char *msg)
{
	for (int i = 0; i <= nfds; ++i)
		if (FD_ISSET(i, fds) && i != server && i != client)
			send(i, msg, strlen(msg), 0);
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

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments");
	int server;
	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == -1)
		ft_error(FATAL);
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));
	if (bind(server, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0 || \
		listen(server, 10) != 0)
	{
		close(server);
		ft_error(FATAL);
	}
	fd_set fds, events;
	FD_ZERO(&fds);
	FD_SET(server, &fds);
	int nfds = server;
	int last = -1;
	char buf[BUFSIZ];
	int ids[FD_SETSIZE] = {-1};
	char *msg[FD_SETSIZE] = {NULL};
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
					socklen_t len;
					struct sockaddr_in cli;
					int client = accept(server, (struct sockaddr *)&cli, &len);
					if (client >= 0)
					{
						FD_SET(client, &fds);
						ids[client] = ++last;
						if (client > nfds)
							nfds = client;
						bzero(buf, BUFSIZ);
						sprintf(buf, "server: client %d just arrived\n", last);
						send_message(&fds, server, client, nfds, buf);
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
						if (i == nfds)
							--nfds;
						bzero(buf, BUFSIZ);
						sprintf(buf, "server: client %d just left\n", ids[i]);
						ids[i] = -1;
						send_message(&fds, server, i, nfds, buf);
					}
					else if (ret > 0)
					{
						msg[i] = str_join(msg[i], buf);
						if (msg[i] == NULL)
							ft_fail(&fds, msg, nfds);
						char *line = NULL;
						ret = extract_message(&msg[i], &line);
						while (ret > 0)
						{
							char *temp = calloc(30, sizeof(char));
							if (temp == NULL)
							{
								free(line);
								ft_fail(&fds, msg, nfds);
							}
							sprintf(temp, "client %d: ", ids[i]);
							temp = str_join(temp, line);
							free(line);
							if (temp == NULL)
								ft_fail(&fds, msg, nfds);
							line = NULL;
							send_message(&fds, server, i, nfds, temp);
							free(temp);
							ret = extract_message(&msg[i], &line);
						}
						if (ret == -1)
							ft_fail(&fds, msg, nfds);
					}
				}
			}
		}
	}
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
