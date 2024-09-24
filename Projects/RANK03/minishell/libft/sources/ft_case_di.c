/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:20:35 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:32:07 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_zeroone(const char *str, int *i, int number, int *len)
{
	int	cutsize;
	int	strsize;
	int	printsize;

	strsize = ft_nbrlen_ten(number, 10);
	cutsize = ft_precision(str, i);
	printsize = ft_width(str, i);
	{
		if (cutsize == 0 || cutsize == -3)
		{
			if (cutsize < strsize)
				cutsize = strsize;
			ft_checksignal(str, i, number, len);
			while (printsize-- > (cutsize + ft_sps(str, i, number)))
				ft_putchar_len('0', len);
		}
		else if (cutsize > 0 || cutsize == -1)
		{
			if (cutsize < strsize)
				cutsize = strsize;
			while (printsize-- > (cutsize + ft_sps(str, i, number)))
				ft_putchar_len(' ', len);
			ft_checksignal(str, i, number, len);
		}
	}
}

static void	ft_cutsizezeros(const char *str, int *i, int number, int *len)
{
	int	cutsize;
	int	strsize;
	int	printsize;
	int	zeros;

	strsize = ft_nbrlen_ten(number, 10);
	cutsize = ft_precision(str, i);
	printsize = ft_width(str, i);
	zeros = ft_zero(str, i);
	if (zeros == 0)
	{
		if (cutsize < strsize)
			cutsize = strsize;
		while (printsize-- > (cutsize + ft_sps(str, i, number)))
			ft_putchar_len(' ', len);
	}
	else if (zeros == 1)
		ft_zeroone(str, i, number, len);
	ft_sps(str, i, number);
	if (zeros == 0)
		ft_checksignal(str, i, number, len);
}

static void	ft_print_right(const char *str, va_list args, int *i, int *len)
{
	va_list	dst;
	int		cutsize;
	int		strsize;
	int		*number;

	strsize = 0;
	va_copy(dst, args);
	strsize = ft_nbrlen_ten(va_arg(dst, int), 10);
	number = malloc(sizeof(int) * strsize);
	*number = va_arg(args, int);
	cutsize = ft_precision(str, i);
	if (cutsize <= strsize)
		cutsize = strsize;
	ft_cutsizezeros(str, i, *number, len);
	ft_putstr_lenszeros(len, &strsize, &cutsize);
	ft_strsizenumber(str, i, *number, len);
	va_end(dst);
	free(number);
}

static void	ft_print_left(const char *str, va_list args, int *i, int *len)
{
	va_list	dst;
	int		cutsize;
	int		strsize;
	int		printsize;
	int		*number;

	va_copy(dst, args);
	strsize = 0;
	strsize = ft_nbrlen_ten(va_arg(args, int), 10);
	number = malloc(sizeof(int) * strsize);
	*number = va_arg(dst, int);
	cutsize = ft_precision(str, i);
	printsize = ft_width(str, i);
	ft_checksignal(str, i, *number, len);
	ft_putstr_lenszeros(len, &strsize, &cutsize);
	ft_cutsizenumber(&cutsize, *number, len);
	if (cutsize <= strsize)
		cutsize = strsize;
	while (printsize-- > (cutsize + ft_sps(str, i, *number)))
		ft_putchar_len(' ', len);
	va_end(dst);
	free(number);
}

void	ft_case_di(const char *str, va_list args, int *i, int *len)
{
	int	justify;

	justify = ft_minus(str, i);
	if (justify == 0)
		ft_print_right(str, args, i, len);
	else if (justify == 1)
		ft_print_left(str, args, i, len);
	while (str[*i] != 'd' && str[*i] != 'i')
		(*i)++;
}
