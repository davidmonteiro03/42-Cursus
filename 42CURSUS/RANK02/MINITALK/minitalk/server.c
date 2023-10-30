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
	static char	character;

	if (sign != SIGUSR1 && sign != SIGUSR2)
	{
		i = 0;
		character = 0;
		return ;
	}
	if (sign == SIGUSR1)
		character |= (1 << i);
	i++;
	if (i == 8)
	{
		if (character == 0)
			ft_putendl_fd("", 1);
		ft_printf(BGRN "%c" BWHT, character);
		i = 0;
		character = 0;
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
	ft_printf(BCYN "SERVER PID" BWHT ": " BGRN "%d" BWHT "\n", pid);
	signal(SIGUSR1, sign_handler);
	signal(SIGUSR2, sign_handler);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
