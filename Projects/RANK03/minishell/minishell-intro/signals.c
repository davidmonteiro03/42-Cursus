/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 07:28:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/15 15:26:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

void	control(int signal)
{
	if (signal == SIGINT)
		printf("\nwrite: ");
}

int	main(void)
{
	char	*line;

	signal(SIGINT, control);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		line = readline("write: ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
	}
	clear_history();
	return (0);
}
