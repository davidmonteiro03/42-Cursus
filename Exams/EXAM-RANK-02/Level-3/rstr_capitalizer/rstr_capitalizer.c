/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:39:55 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 16:15:36 by dcaetano         ###   ########.fr       */
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

void	ft_capitalize(char *curr, char *next)
{
	if (*curr >= 'A' && *curr <= 'Z' && !(!*next || ft_isspace(*next)))
		*curr += 32;
	else if (*curr >= 'a' && *curr <= 'z' && (!*next || ft_isspace(*next)))
		*curr -= 32;
}

void	rstr_capitalizer(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			ft_capitalize(str, str + 1);
		write(1, str++, 1);
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		while (*++argv)
			rstr_capitalizer(*argv);
	else
		write(1, "\n", 1);
	return (0);
}
