/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:25:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 18:53:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_toupper(int c)
{
	return (c - 32 * (c >= 'a' && c <= 'z'));
}

void	ft_execute(char *c)
{
	int	limit;

	limit = ft_toupper(*c) - 65 + 1;
	*c += (26 - limit + 1) - limit;
}

void	alpha_mirror(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			ft_execute(str);
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}
