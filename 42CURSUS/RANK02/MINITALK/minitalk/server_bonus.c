/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:50:18 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/30 09:32:05 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_bonus.h"

void	build_char(int sign, siginfo_t *info, void *content)
{
	static int		i;
	static wchar_t	character;

	(void)content;
	if (sign != SIGUSR1 && sign != SIGUSR2)
	{
		i = 0;
		character = 0;
		return ;
	}
	if (sign == SIGUSR1)
		character |= (1 << i);
	i++;
	if (i == 32)
	{
		if (character == 0)
		{
			ft_putendl_fd("", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &character, 1);
		i = 0;
		character = 0;
	}
}

void	sign_handler(int bit, siginfo_t *info, void *content)
{
	build_char(bit, info, content);
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	build_char(0, NULL, NULL);
	ft_printf(BCYN "SERVER PID" BWHT ": " BGRN "%d" BWHT "\n", pid);
	action.sa_sigaction = &sign_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
