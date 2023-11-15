/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:37:37 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/15 17:41:31 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#define NUM_LINES 10

int	main(void)
{
	char	*line;
	int		i;

	i = -1;
	while (++i < NUM_LINES)
	{
		line = readline("Write something: ");
		if (!line)
			return (1);
		if (!*line)
			return (free(line), 0);
		add_history(line);
		free(line);
	}
	rl_clear_history();
	line = readline("Try to remember something: ");
	if (!line)
		return (1);
	if (!*line)
		return (free(line), 0);
	free(line);
	return (0);
}
