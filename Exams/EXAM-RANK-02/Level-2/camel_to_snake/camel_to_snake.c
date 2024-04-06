/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:08:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 16:13:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

void	camel_to_snake(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
		{
			if (*str >= 'A' && *str <= 'Z')
			{
				write(1, "_", 1);
				*str += 32;
			}
			write(1, str, 1);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	write(1, "\n", 1);
	return (0);
}
