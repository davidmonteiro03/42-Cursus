/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:37:14 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 15:46:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	snake_to_camel(char *str)
{
	char	c;

	while (*str)
	{
		while (*str && *str == '_')
			str++;
		while (*str && *str != '_')
		{
			c = *str;
			if (*(str - 1) == '_' && c >= 'a' && c <= 'z')
				c -= 32;
			write(1, &c, 1);
			str++;
		}
		while (*str && *str == '_')
			str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		snake_to_camel(argv[1]);
	write(1, "\n", 1);
	return (0);
}
