/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations_strings_two.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:30:54 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*display_basecheck(int *upper)
{
	if (*upper == 0)
		return ("0123456789abcdef");
	if (*upper == 1)
		return ("0123456789ABCDEF");
	return (0);
}

void	display_putchar_len(int c, t_tmp *tmp)
{
	write(tmp->fd, &c, 1);
	(tmp->len)++;
}

void	display_puthex_pre(const char *str, t_tmp *tmp, int hex)
{
	int	sharp;
	int	upper;

	upper = 0;
	sharp = display_sharp(str, tmp);
	display_searchupper(str, tmp, &upper);
	if (sharp == 1 || hex == -1)
	{
		if (upper == 1)
		{
			write(tmp->fd, "0X", 2);
			(tmp->len) += 2;
		}
		else if (upper == 0 || hex == -1)
		{
			write(tmp->fd, "0x", 2);
			(tmp->len) += 2;
		}
	}
}

void	display_searchupper(const char *str, t_tmp *tmp, int *upper)
{
	int	j;

	j = 0;
	while (str[tmp->i + j] != '\0' && str[tmp->i + j -1] != 'x'
		&& str[tmp->i + j - 1] != 'X' && str[tmp->i + j - 1] != 'p')
	{
		if (str[tmp->i + j] == 'X')
			*upper = 1;
		j++;
	}
}

int	display_uppercheck(const char *str, t_tmp *tmp)
{
	int	j;

	j = 0;
	while (str[tmp->i + j] != '\0')
	{
		if (str[tmp->i + j] == 'x')
			return (0);
		if (str[tmp->i + j] == 'X')
			return (1);
		j++;
	}
	return (0);
}
