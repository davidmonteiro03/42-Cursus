/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:56:05 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 19:12:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_find_position(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	hidenp(char *s1, char *s2)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (s1[i])
	{
		pos = ft_find_position(&s2[pos], s1[i]);
		if (pos == -1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	status;

	status = 0;
	if (argc == 3)
	{
		status = hidenp(argv[1], argv[2]);
		if (status == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
