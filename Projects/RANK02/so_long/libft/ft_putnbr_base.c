/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:36:36 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 11:04:08 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, unsigned int base, \
	int *ret, int (*f)(int))
{
	const char	*str_base;

	str_base = "0123456789abcdef";
	if (nbr > base - 1)
	{
		ft_putnbr_base(nbr / base, base, ret, f);
		ft_putnbr_base(nbr % base, base, ret, f);
	}
	else
	{
		if (f == NULL)
			ft_putchar(str_base[nbr % base], ret);
		else
			ft_putchar(f(str_base[nbr % base]), ret);
	}
}
