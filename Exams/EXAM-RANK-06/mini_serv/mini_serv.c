#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
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
	write(2, error, strlen(error));
	write(2, "\n", 1);
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments");
	int serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd < 0)
		ft_error("Fatal error");
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));
	if (bind(serverfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 || \
		listen(serverfd, 10) < 0)
		ft_error("Fatal error");
	fd_set afds, rfds, wfds;
	int ids[1024];
	char *msg[1024];
	int next_id = 0;
	const int BUFFER_READ = 1024;
	const int BUFFER_WRITE = 100;
	char buffer_read[BUFFER_READ];
	char buffer_write[BUFFER_WRITE];
	FD_ZERO(&afds);
	FD_SET(serverfd, &afds);
	int maxfd = serverfd;
	while (1)
	{
		rfds = wfds = afds;
		if (select(maxfd + 1, &rfds, &wfds, NULL, NULL) < 0)
			ft_error("Fatal error");
		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue ;
			if (fd == serverfd)
			{
				struct sockaddr_in cli;
				socklen_t len = sizeof(cli);
				int clientfd = accept(serverfd, (struct sockaddr *)&cli, &len);
				if (clientfd >= 0)
				{
					FD_SET(clientfd, &afds);
					if (clientfd > maxfd)
						maxfd = clientfd;
					ids[clientfd] = next_id++;
					msg[clientfd] = NULL;
					bzero(buffer_write, BUFFER_WRITE);
					sprintf(buffer_write, "server: client %d just arrived\n", ids[clientfd]);
					for (int i = 0; i <= maxfd; i++)
						if (FD_ISSET(i, &wfds) && i != clientfd)
							send(i, buffer_write, strlen(buffer_write), 0);
					break ;
				}
			}
			else
			{
				bzero(buffer_read, BUFFER_READ);
				int ret = recv(fd, buffer_read, sizeof(buffer_read) - 1, 0);
				if (ret == 0)
				{
					bzero(buffer_write, BUFFER_WRITE);
					sprintf(buffer_write, "server: client %d just left\n", ids[fd]);
					for (int i = 0; i <= maxfd; i++)
						if (FD_ISSET(i, &wfds) && i != fd)
							send(i, buffer_write, strlen(buffer_write), 0);
					if (msg[fd])
						free(msg[fd]);
					close(fd);
					FD_CLR(fd, &afds);
					break ;
				}
				else
				{
					char *temp_msg;
					buffer_read[ret] = '\0';
					msg[fd] = str_join(msg[fd], buffer_read);
					while (extract_message(&msg[fd], &temp_msg))
					{
						bzero(buffer_write, BUFFER_WRITE);
						sprintf(buffer_write, "client %d: ", ids[fd]);
						for (int i = 0; i <= maxfd; i++)
						{
							if (FD_ISSET(i, &wfds) && i != fd)
							{
								send(i, buffer_write, strlen(buffer_write), 0);
								send(i, temp_msg, strlen(temp_msg), 0);
							}
						}
					}
					free(temp_msg);
				}
			}
		}
	}
	return (0);
}
