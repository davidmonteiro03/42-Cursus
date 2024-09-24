/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:01:33 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_print_nulls(const char *str, int *i, int *len)
{
	int		cutsize;
	int		printsize;
	int		justify;
	int		strsize;

	cutsize = ft_precision(str, i);
	printsize = ft_width(str, i);
	justify = ft_minus(str, i);
	strsize = 0;
	if ((cutsize >= 0 && cutsize <= 5) || cutsize == -1)
		ft_putstr_lenspaces(len, &strsize, &printsize);
	else
	{
		printsize -= 6;
		if (justify == 1)
		{
			ft_putstr_lennull(len);
			ft_putstr_lenspaces(len, &strsize, &printsize);
		}
		else if (justify == 0)
		{
			ft_putstr_lenspaces(len, &strsize, &printsize);
			ft_putstr_lennull(len);
		}
	}
}

static void	ft_print( const char *str, va_list args, int *i, int *len)
{
	va_list	dst;
	int		strsize;
	int		cutsize;
	int		printsize;
	int		justify;

	va_copy(dst, args);
	strsize = ft_strlen(va_arg(dst, char *));
	cutsize = ft_precision(str, i);
	printsize = ft_width(str, i);
	justify = ft_minus(str, i);
	if (cutsize == -1)
		strsize = 0;
	else if (cutsize >= 0 && strsize > cutsize)
		strsize = cutsize;
	if (justify == 0)
		ft_putstr_lenspaces(len, &strsize, &printsize);
	else if (justify == 1)
		ft_putstr_len(va_arg(args, char *), len, &strsize);
	if (justify == 0)
		ft_putstr_len(va_arg(args, char *), len, &strsize);
	else if (justify == 1)
		ft_putstr_lenspaces(len, &strsize, &printsize);
	va_end(dst);
}

void	ft_case_s(const char *str, va_list args, int *i, int *len)
{
	va_list	dst;

	va_copy(dst, args);
	if (va_arg(dst, char *))
		ft_print(str, args, i, len);
	else
		ft_print_nulls(str, i, len);
	while (str[*i] != 's')
		(*i)++;
	va_end(dst);
}
