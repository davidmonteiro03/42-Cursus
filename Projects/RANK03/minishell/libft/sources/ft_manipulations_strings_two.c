/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulations_strings_two_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:30:54 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_len(int c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

int	ft_uppercheck(const char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i + j] != '\0')
	{
		if (str[*i + j] == 'x')
			return (0);
		if (str[*i + j] == 'X')
			return (1);
		j++;
	}
	return (0);
}

char	*ft_basecheck(int *upper)
{
	if (*upper == 0)
		return ("0123456789abcdef");
	if (*upper == 1)
		return ("0123456789ABCDEF");
	return (0);
}

void	ft_searchupper(const char *str, int *i, int *upper)
{
	int	j;

	j = 0;
	while (str[*i + j] != '\0' && str[*i + j -1] != 'x'
		&& str[*i + j - 1] != 'X' && str[*i + j - 1] != 'p')
	{
		if (str[*i + j] == 'X')
			*upper = 1;
		j++;
	}
}

void	ft_puthex_pre(const char *str, int *i, int *len, int hex)
{
	int	sharp;
	int	upper;

	upper = 0;
	sharp = ft_sharp(str, i);
	ft_searchupper(str, i, &upper);
	if (sharp == 1 || hex == -1)
	{
		if (upper == 1)
		{
			write(1, "0X", 2);
			(*len) += 2;
		}
		else if (upper == 0 || hex == -1)
		{
			write(1, "0x", 2);
			(*len) += 2;
		}
	}
}
