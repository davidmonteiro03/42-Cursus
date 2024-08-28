/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:08:58 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 17:31:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, unsigned int base, int uppercase,
		t_help *help)
{
	static const char	*setlower = "0123456789abcdef";
	static const char	*setupper = "0123456789ABCDEF";

	if (help == NULL)
		return ;
	if (nbr > base - 1)
	{
		ft_putnbr_base(nbr / base, base, uppercase, help);
		ft_putnbr_base(nbr % base, base, uppercase, help);
	}
	else
	{
		if (uppercase != 0)
			ft_putchar(setupper[nbr % base], help);
		else
			ft_putchar(setlower[nbr % base], help);
	}
}
