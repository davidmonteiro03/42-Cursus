/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:39:35 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/03 11:53:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
