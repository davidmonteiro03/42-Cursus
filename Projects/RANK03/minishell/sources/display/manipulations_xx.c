/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations_xx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 07:41:08 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_cutsizenumber_xx(const char *str, va_list args, t_tmp *tmp)
{
	va_list	dst;
	int		upper;
	int		cutsize;

	va_copy(dst, args);
	upper = 0;
	upper = display_uppercheck(str, tmp);
	cutsize = display_precision(str, tmp);
	if (cutsize <= 0 && cutsize != -3)
	{
		if (va_arg(dst, int) == 0)
			display_putchar_len(' ', tmp);
		else
			display_putnbr_base_x(va_arg(args, int), tmp,
				display_basecheck(&upper));
	}
	else if (cutsize > 0 || cutsize == -3)
		display_putnbr_base_x(va_arg(args, int), tmp,
			display_basecheck(&upper));
	va_end(dst);
}

void	display_strsizenumber_xx(const char *str, t_tmp *tmp, int number)
{
	int	cutsize;
	int	strsize;
	int	printsize;
	int	upper;

	strsize = display_nbrlen_unsigned(number, 16);
	cutsize = display_precision(str, tmp);
	printsize = display_width(str, tmp);
	upper = display_uppercheck(str, tmp);
	if (cutsize <= 0 && cutsize != -3)
	{
		if (number == 0 && printsize > 0)
			display_putchar_len(' ', tmp);
		else if (strsize > 1)
			display_putnbr_base_x(number, tmp, display_basecheck(&upper));
	}
	else if (cutsize > 0 || cutsize == -3)
		display_putnbr_base_x(number, tmp, display_basecheck(&upper));
}
