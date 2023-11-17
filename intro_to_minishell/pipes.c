/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:22:37 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/17 11:32:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	main(int ac, char **av)
{
	pid_t	pid;
	int		fd[2];
	char	buffer[100];

	if (ac != 2)
		return (1);
	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[0]);
		write(fd[1], av[1], strlen(av[1]) + 1);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, sizeof(buffer));
		printf("%s\n", buffer);
	}
	return (0);
}
