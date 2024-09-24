/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulations_xx_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:41:08 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_cutsizenumber_xx(const char *str, va_list args, int *i, int *len)
{
	va_list	dst;
	int		upper;
	int		cutsize;

	va_copy(dst, args);
	upper = 0;
	upper = ft_uppercheck(str, i);
	cutsize = ft_precision(str, i);
	if (cutsize <= 0 && cutsize != -3)
	{
		if (va_arg(dst, int) == 0)
			ft_putchar_len(' ', len);
		else
			ft_putnbr_base_x(va_arg(args, int), len, ft_basecheck(&upper));
	}
	else if (cutsize > 0 || cutsize == -3)
		ft_putnbr_base_x(va_arg(args, int), len, ft_basecheck(&upper));
	va_end(dst);
}

void	ft_strsizenumber_xx(const char *str, int *i, int number, int *len)
{
	int	cutsize;
	int	strsize;
	int	printsize;
	int	upper;

	strsize = ft_nbrlen_unsigned(number, 16);
	cutsize = ft_precision(str, i);
	printsize = ft_width(str, i);
	upper = ft_uppercheck(str, i);
	if (cutsize <= 0 && cutsize != -3)
	{
		if (number == 0 && printsize > 0)
			ft_putchar_len(' ', len);
		else if (strsize > 1)
			ft_putnbr_base_x(number, len, ft_basecheck(&upper));
	}
	else if (cutsize > 0 || cutsize == -3)
		ft_putnbr_base_x(number, len, ft_basecheck(&upper));
}
