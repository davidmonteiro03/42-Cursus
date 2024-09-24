/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 05:22:00 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_print_nil(const char *str, int *i, int *len)
{
	int	justify;
	int	printsize;
	int	strsize;

	strsize = 5;
	justify = ft_minus(str, i);
	printsize = ft_width(str, i);
	if (justify == 1)
	{
		ft_putstr_lennil(len);
		ft_putstr_lenspaces(len, &strsize, &printsize);
	}
	else if (justify == 0)
	{
		ft_putstr_lenspaces(len, &strsize, &printsize);
		ft_putstr_lennil(len);
	}
}

static void	ft_print(const char *str, va_list args, int *i, int *len)
{
	va_list	dst;
	int		justify;
	int		printsize;
	int		strsize;

	va_copy(dst, args);
	strsize = ft_nbrlen(va_arg(dst, unsigned long long int), 16) + 2;
	justify = ft_minus(str, i);
	printsize = ft_width(str, i);
	if (justify == 1)
	{
		ft_puthex_pre(str, i, len, -1);
		ft_putnbr_base(va_arg(args, size_t), len, "0123456789abcdef");
		ft_putstr_lenspaces(len, &strsize, &printsize);
	}
	else if (justify == 0)
	{
		ft_putstr_lenspaces(len, &strsize, &printsize);
		ft_puthex_pre(str, i, len, -1);
		ft_putnbr_base(va_arg(args, size_t), len, "0123456789abcdef");
	}
	va_end(dst);
}

void	ft_case_p(const char *str, va_list args, int *i, int *len)
{
	va_list	dst;

	va_copy(dst, args);
	if (va_arg(dst, size_t))
		ft_print(str, args, i, len);
	else
		ft_print_nil(str, i, len);
	while (str[*i] != 'p')
		(*i)++;
	va_end(dst);
}
