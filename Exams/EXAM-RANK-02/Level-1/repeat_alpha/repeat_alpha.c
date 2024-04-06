/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:22:07 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 16:33:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

char	ft_toupper(char c)
{
	return (c - 32 * (c >= 'a' && c <= 'z'));
}

void	ft_repeat(char c)
{
	int	limit;

	limit = ft_toupper(c) - 65 + 1;
	while (limit-- > 0)
		write(1, &c, 1);
}

void	repeat_alpha(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			ft_repeat(*str);
		else
			write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
