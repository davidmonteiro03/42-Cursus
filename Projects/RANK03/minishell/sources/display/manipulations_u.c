/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:58:25 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	display_checksignal_u(const char *str, t_tmp *tmp, int nb)
{
	int		space;
	int		plus;
	long	n;

	space = display_space(str, tmp);
	plus = display_plus(str, tmp);
	n = 0;
	n = nb;
	if (space == 1 && plus == 0 && n >= 0)
		display_putchar_len(' ', tmp);
	if (n < 0)
		display_putchar_len('-', tmp);
	else if (plus == 1)
		display_putchar_len('+', tmp);
}

void	display_cutsizenumber_u(int *cutsize, int number, t_tmp *tmp)
{
	if (*cutsize <= 0 && *cutsize != -3)
	{
		if (number == 0)
			display_putchar_len(' ', tmp);
		else
			display_putnbr_unsigned(number, tmp);
	}
	else if (*cutsize > 0 || *cutsize == -3)
		display_putnbr_unsigned(number, tmp);
}

int	display_sps_u(const char *str, t_tmp *tmp, int n)
{
	int	space;
	int	plus;

	space = display_space(str, tmp);
	plus = display_plus(str, tmp);
	if (space == 1 || plus == 1 || n < 0)
		return (1);
	return (0);
}

void	display_strsizenumber_u(const char *str, t_tmp *tmp, int number)
{
	int	cutsize;
	int	strsize;
	int	printsize;

	strsize = display_nbrlen_ten(number, 10);
	cutsize = display_precision(str, tmp);
	printsize = display_width(str, tmp);
	if (cutsize <= 0 && cutsize != -3)
	{
		if (number == 0 && printsize > 0)
			display_putchar_len(' ', tmp);
		else if ((strsize > 1 || (cutsize == -1
					&& printsize >= -1)) && number != 0)
			display_putnbr_unsigned(number, tmp);
	}
	else if (cutsize > 0 || cutsize == -3)
		display_putnbr_unsigned(number, tmp);
}
