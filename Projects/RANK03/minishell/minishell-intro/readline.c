/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:32:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/15 17:41:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

int	main(void)
{
	char	*line;

	line = readline("Write something: ");
	if (!line)
		return (1);
	if (!*line)
		return (free(line), 0);
	printf("You wrote this: %s\n", line);
	free(line);
	return (0);
}
