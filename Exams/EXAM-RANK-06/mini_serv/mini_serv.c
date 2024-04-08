/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:24:23 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/08 09:24:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

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

void ft_error(const char *error)
{
	write(STDERR_FILENO, error, strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

void ft_close(fd_set *fds, int fd_max, char **msg, int status)
{
	for (int i = 0; i <= fd_max; i++)
	{
		if (FD_ISSET(i, fds))
		{
			FD_CLR(i, fds);
			close(i);
			free(msg[i]);
		}
	}
	if (status == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
	ft_error("Fatal error");
}

void ft_broadcast(fd_set *fds, int fd_max, int server, int client, char *msg)
{
	for (int i = 0; i <= fd_max; i++)
		if (FD_ISSET(i, fds) && i != server && i != client)
			send(i, msg, strlen(msg), 0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments");
	int server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == -1)
		ft_error("Fatal error");
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));
	if (bind(server, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0 || \
		listen(server, 100) != 0)
	{
		close(server);
		ft_error("Fatal error");
	}
	fd_set fds, events;
	int fd_max = server;
	int ids[FD_SETSIZE] = {-1};
	char *msg[FD_SETSIZE] = {NULL};
	char buf[BUFSIZ];
	int last = -1;
	FD_ZERO(&fds);
	FD_SET(server, &fds);
	while (1)
	{
		events = fds;
		if (select(fd_max + 1, &events, NULL, NULL, NULL) == -1)
			ft_close(&fds, fd_max, msg, EXIT_FAILURE);
		for (int i = 0; i <= fd_max; i++)
		{
			if (FD_ISSET(i, &events))
			{
				if (i == server)
				{
					struct sockaddr_in cli;
					socklen_t len;
					int client = accept(server, (struct sockaddr *)&cli, &len);
					if (client >= 0)
					{
						FD_SET(client, &fds);
						if (client > fd_max)
							fd_max = client;
						ids[client] = ++last;
						bzero(&buf, BUFSIZ);
						sprintf(buf, "server: client %d just arrived\n", ids[client]);
						ft_broadcast(&fds, fd_max, server, client, buf);
					}
				}
				else
				{
					bzero(&buf, BUFSIZ);
					ssize_t ret = recv(i, buf, BUFSIZ - 1, 0);
					if (ret <= 0)
					{
						FD_CLR(i, &fds);
						close(i);
						free(msg[i]);
						msg[i] = NULL;
						if (i == fd_max)
							--fd_max;
						bzero(&buf, BUFSIZ);
						sprintf(buf, "server: client %d just left\n", ids[i]);
						ids[i] = -1;
						ft_broadcast(&fds, fd_max, server, i, buf);
					}
					else if (ret > 0)
					{
						msg[i] = str_join(msg[i], buf);
						if (msg[i] == NULL)
							ft_close(&fds, fd_max, msg, EXIT_FAILURE);
						char *line = NULL;
						ret = extract_message(&msg[i], &line);
						while (ret > 0)
						{
							char *temp = calloc(30, sizeof(char));
							if (temp == NULL)
							{
								free(line);
								ft_close(&fds, fd_max, msg, EXIT_FAILURE);
							}
							sprintf(temp, "client %d: ", ids[i]);
							temp = str_join(temp, line);
							free(line);
							if (temp == NULL)
								ft_close(&fds, fd_max, msg, EXIT_FAILURE);
							ft_broadcast(&fds, fd_max, server, i, temp);
							free(temp);
							ret = extract_message(&msg[i], &line);
						}
					}
				}
			}
		}
	}
	return ((void)argc, (void)argv, EXIT_SUCCESS);
}
