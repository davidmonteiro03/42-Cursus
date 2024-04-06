/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 11:57:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 12:27:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	first_word(char *str)
{
	char	*first;

	first = NULL;
	while (*str)
	{
		if (!ft_isspace(*str) && first == NULL)
			first = str;
		str++;
	}
	if (first != NULL)
		while (*first && !ft_isspace(*first))
			write(1, first++, 1);
}

void	rostring(const char *str)
{
	char	*tmp;
	int		count;

	tmp = (char *)str;
	count = 0;
	while (*tmp)
	{
		while (*tmp && ft_isspace(*tmp))
			tmp++;
		if (count > 0)
		{
			while (*tmp && !ft_isspace(*tmp))
				write(1, tmp++, 1);
			write(1, " ", 1);
		}
		else
			while (*tmp && !ft_isspace(*tmp))
				tmp++;
		if (*tmp)
			count++;
		while (*tmp && ft_isspace(*tmp))
			tmp++;
	}
	tmp = (char *)str;
	first_word(tmp);
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
