/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:39:55 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 11:56:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	ft_capitalize(char *curr, char *prev)
{
	if (*curr >= 'A' && *curr <= 'Z' && !(!*prev || ft_isspace(*prev)))
		*curr += 32;
	else if (*curr >= 'a' && *curr <= 'z' && (!*prev || ft_isspace(*prev)))
		*curr -= 32;
}

void	str_capitalizer(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			ft_capitalize(str, str - 1);
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		while (*++argv)
			str_capitalizer(*argv);
	else
		write(1, "\n", 1);
	return (0);
}
