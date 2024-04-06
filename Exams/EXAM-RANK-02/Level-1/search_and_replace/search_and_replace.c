/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 13:08:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 13:14:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	search_and_replace(char *str, char old, char new)
{
	while (*str)
	{
		if (*str == old)
			*str = new;
		write(1, str++, 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4 && !argv[2][1] && !argv[3][1])
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}
