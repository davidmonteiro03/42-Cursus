/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:40:30 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 08:35:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	send_to_server(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
	}
	usleep(50);
}

int	main(int ac, char **av)
{
	static int	pid;
	int			i;

	if (ac != 3)
		return (EXIT_FAILURE);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
		send_to_server(pid, av[2][i++]);
	send_to_server(pid, av[2][i]);
	return (EXIT_SUCCESS);
}
