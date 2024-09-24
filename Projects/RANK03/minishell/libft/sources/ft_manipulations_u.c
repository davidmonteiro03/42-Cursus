/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulations_u_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:58:25 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_checksignal_u(const char *str, int *i, int nb, int *len)
{
	int		space;
	int		plus;
	long	n;

	space = ft_space(str, i);
	plus = ft_plus(str, i);
	n = 0;
	n = nb;
	if (space == 1 && plus == 0 && n >= 0)
		ft_putchar_len(' ', len);
	if (n < 0)
		ft_putchar_len('-', len);
	else if (plus == 1)
		ft_putchar_len('+', len);
}

int	ft_sps_u(const char *str, int *i, int n)
{
	int	space;
	int	plus;

	space = ft_space(str, i);
	plus = ft_plus(str, i);
	if (space == 1 || plus == 1 || n < 0)
		return (1);
	return (0);
}

void	ft_cutsizenumber_u(int *cutsize, int number, int *len)
{
	if (*cutsize <= 0 && *cutsize != -3)
	{
		if (number == 0)
			ft_putchar_len(' ', len);
		else
			ft_putnbr_unsigned(number, len);
	}
	else if (*cutsize > 0 || *cutsize == -3)
		ft_putnbr_unsigned(number, len);
}

void	ft_strsizenumber_u(const char *str, int *i, int number, int *len)
{
	int	cutsize;
	int	strsize;
	int	printsize;

	strsize = ft_nbrlen_ten(number, 10);
	cutsize = ft_precision(str, i);
	printsize = ft_width(str, i);
	if (cutsize <= 0 && cutsize != -3)
	{
		if (number == 0 && printsize > 0)
			ft_putchar_len(' ', len);
		else if ((strsize > 1 || (cutsize == -1
					&& printsize >= -1)) && number != 0)
			ft_putnbr_unsigned(number, len);
	}
	else if (cutsize > 0 || cutsize == -3)
		ft_putnbr_unsigned(number, len);
}
