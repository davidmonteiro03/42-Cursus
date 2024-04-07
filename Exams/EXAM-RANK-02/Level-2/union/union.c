/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:05:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/07 08:09:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_union(char *s1, char *s2)
{
	int	local[256];
	int	i;

	i = 0;
	while (i < 256)
		local[i++] = 0;
	while (*s1)
	{
		if (local[(int)*s1] == 0)
		{
			local[(int)*s1] = 1;
			write(1, s1, 1);
		}
		s1++;
	}
	while (*s2)
	{
		if (local[(int)*s2] == 0)
		{
			local[(int)*s2] = 1;
			write(1, s2, 1);
		}
		s2++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
