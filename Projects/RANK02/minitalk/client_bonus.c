/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:01:34 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 09:08:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	sign_handler(int sig)
{
	(void)sig;
	ft_putendl_fd("Message sent successfully!", 1);
	exit(EXIT_SUCCESS);
}

void	send_to_server(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
}

int	main(int ac, char **av)
{
	static int	pid;
	int			i;

	signal(SIGUSR1, sign_handler);
	if (ac != 3)
		return (EXIT_FAILURE);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_to_server(pid, av[2][i++]);
	send_to_server(pid, av[2][i]);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
