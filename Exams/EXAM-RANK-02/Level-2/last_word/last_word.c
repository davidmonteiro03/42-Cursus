/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:39:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 11:36:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

void	last_word(char *str)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (!ft_isspace(*str))
			last = str;
		str++;
	}
	if (last != NULL)
	{
		while (*last && !ft_isspace(*last))
			last--;
		last++;
		while (*last && !ft_isspace(*last))
			write(1, last++, 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
