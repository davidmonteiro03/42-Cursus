/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_serv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:41:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/03/26 13:28:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                  INCLUDES                                  */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

/* ************************************************************************** */
/*                                  DISPLAY                                   */
/* ************************************************************************** */

void ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(int fd, char *str)
{
	if (str == NULL)
		write(fd, "(null)", 6);
	else
		write(fd, str, strlen(str));
}

void ft_putnbr_fd(int fd, int nbr)
{
	if (nbr == -2147483648)
		return (ft_putstr_fd(fd, "-2147483648"));
	if (nbr < 0)
	{
		ft_putchar_fd(fd, '-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(fd, nbr / 10);
		ft_putnbr_fd(fd, nbr % 10);
	}
	else
		ft_putchar_fd(fd, nbr + '0');
}

void ft_putendl_fd(int fd, char *str)
{
	ft_putstr_fd(fd, str);
	ft_putchar_fd(fd, '\n');
}

/* ************************************************************************** */
/*                                   ERRORS                                   */
/* ************************************************************************** */

void error(char *error)
{
	ft_putendl_fd(2, error);
	exit(1);
}

/* ************************************************************************** */
/*                                    MAIN                                    */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	socklen_t len;
	int port, sockfd, connfd;
	struct sockaddr_in servaddr, client;
	if (argc != 2)
		error("Wrong number of arguments");
	port = atoi(argv[1]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		error("Fatal error");
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(port);
	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
		error("Fatal error");
	while (1)
	{
		if (listen(sockfd, 10) != 0)
			error("Fatal error");
		len = sizeof(client);
		connfd = accept(sockfd, (struct sockaddr *)&client, &len);
		if (connfd < 0)
			error("Fatal error");
		ft_putendl_fd(connfd, "Hi from server!");
	}
	return (0);
}
