/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:26:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 10:30:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *ret)
{
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648", ret));
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', ret);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, ret);
		ft_putnbr(nbr % 10, ret);
	}
	else
		ft_putchar(nbr % 10 + '0', ret);
}
