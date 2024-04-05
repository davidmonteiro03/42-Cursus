/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 09:45:10 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/05 10:05:21 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	inter(char *str1, char *str2)
{
	char	*tmp;
	int		local[256];
	int		i;

	i = 0;
	while (i < 256)
		local[i++] = 0;
	while (*str1)
	{
		tmp = str2;
		while (*tmp)
		{
			if (*str1 == *tmp)
			{
				if (local[(int)*str1] == 0)
				{
					local[(int)*str1] = 1;
					write(1, str1, 1);
				}
			}
			tmp++;
		}
		str1++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
