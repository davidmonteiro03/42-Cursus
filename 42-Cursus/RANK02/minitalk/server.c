/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:38:03 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 09:44:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	build_char(int sign)
{
	static int	i;
	static char	c;

	if (sign != SIGUSR1 && sign != SIGUSR2)
	{
		i = 0;
		c = 0;
		return ;
	}
	if (sign == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	sign_handler(int bit)
{
	build_char(bit);
	signal(bit, sign_handler);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	build_char(0);
	ft_printf("SERVER PID: %d\n", pid);
	signal(SIGUSR1, sign_handler);
	signal(SIGUSR2, sign_handler);
	while (1)
	{
	}
	return (EXIT_SUCCESS);
}
