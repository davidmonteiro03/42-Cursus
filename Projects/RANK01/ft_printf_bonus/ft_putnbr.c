/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:08:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 15:09:09 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, t_help *help)
{
	if (help == NULL)
		return ;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648", help));
	if (nbr < 0)
	{
		nbr = -nbr;
		ft_putchar('-', help);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, help);
		ft_putnbr(nbr % 10, help);
	}
	else
		ft_putchar(nbr % 10 + '0', help);
}
