/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 08:13:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/07 08:43:50 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

char	ft_tolower(char c)
{
	return (c + 32 * (c >= 'A' && c <= 'Z'));
}

int	ft_find(const char *str, const char c, int max)
{
	int	i;

	i = 0;
	while (str[i] && i < max)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int			res;
	int			sign;
	int			pos;
	const char	*pack;

	res = 0;
	sign = 1;
	pack = "0123456789abcdef";
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	pos = ft_find(pack, ft_tolower(*str), str_base);
	while (*str && pos != -1)
	{
		res = res * str_base + pos;
		pos = ft_find(pack, ft_tolower(*(++str)), str_base);
	}
	return (res * sign);
}
