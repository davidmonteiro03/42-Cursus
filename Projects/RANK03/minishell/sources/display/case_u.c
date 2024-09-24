/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 01:48:57 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:23:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_zeroone(const char *str, t_tmp *tmp, int number)
{
	int	cutsize;
	int	strsize;
	int	printsize;

	strsize = display_nbrlen_unsigned(number, 10);
	cutsize = display_precision(str, tmp);
	printsize = display_width(str, tmp);
	{
		if (cutsize == 0 || cutsize == -3)
		{
			if (cutsize < strsize)
				cutsize = strsize;
			while (printsize-- > (cutsize))
				display_putchar_len('0', tmp);
		}
		else if (cutsize > 0)
		{
			if (cutsize < strsize)
				cutsize = strsize;
			while (printsize-- > (cutsize))
				display_putchar_len(' ', tmp);
		}
	}
}

static void	ft_cutsizezeros(const char *str, t_tmp *tmp, int number)
{
	int	cutsize;
	int	strsize;
	int	printsize;
	int	zeros;

	strsize = display_nbrlen_unsigned(number, 10);
	cutsize = display_precision(str, tmp);
	printsize = display_width(str, tmp);
	zeros = display_zero(str, tmp);
	if (cutsize <= strsize)
		cutsize = strsize;
	if (zeros == 0)
	{
		if (cutsize < strsize)
			cutsize = strsize;
		while (printsize-- > (cutsize))
			display_putchar_len(' ', tmp);
	}
	else if (zeros == 1)
		ft_zeroone(str, tmp, number);
}

static void	ft_print_right(const char *str, va_list args, t_tmp *tmp)
{
	va_list	dst;
	int		cutsize;
	int		strsize;
	int		*number;

	strsize = 0;
	va_copy(dst, args);
	strsize = display_nbrlen_unsigned(va_arg(dst, int), 10);
	number = malloc(sizeof(int) * strsize);
	*number = va_arg(args, int);
	cutsize = display_precision(str, tmp);
	if (cutsize <= strsize)
		cutsize = strsize;
	ft_cutsizezeros(str, tmp, *number);
	display_putstr_lenszeros(tmp, &strsize, &cutsize);
	display_strsizenumber_u(str, tmp, *number);
	va_end(dst);
	free(number);
}

static void	ft_print_left(const char *str, va_list args, t_tmp *tmp)
{
	va_list	dst;
	int		cutsize;
	int		strsize;
	int		printsize;
	int		*number;

	va_copy(dst, args);
	strsize = 0;
	strsize = display_nbrlen_unsigned(va_arg(args, int), 10);
	number = malloc(sizeof(int) * strsize);
	*number = va_arg(dst, int);
	cutsize = display_precision(str, tmp);
	printsize = display_width(str, tmp);
	display_putstr_lenszeros(tmp, &strsize, &cutsize);
	display_cutsizenumber_u(&cutsize, *number, tmp);
	if (cutsize <= strsize)
		cutsize = strsize;
	while (printsize-- > (cutsize))
		display_putchar_len(' ', tmp);
	va_end(dst);
	free(number);
}

void	display_case_u(const char *str, va_list args, t_tmp *tmp)
{
	int	justify;

	justify = display_minus(str, tmp);
	if (justify == 0)
		ft_print_right(str, args, tmp);
	else if (justify == 1)
		ft_print_left(str, args, tmp);
	while (str[tmp->i] != 'u')
		(tmp->i)++;
}
