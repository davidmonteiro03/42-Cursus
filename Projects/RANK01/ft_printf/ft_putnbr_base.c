/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:53:01 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/06 19:57:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int num, unsigned int base, int *len, char c)
{
	char	*base_str;

	if (c == ft_tolower(c))
		base_str = "0123456789abcdef";
	else
		base_str = "0123456789ABCDEF";
	if (num > base - 1)
	{
		ft_putnbr_base(num / base, base, len, c);
		ft_putnbr_base(num % base, base, len, c);
	}
	else
		ft_putchar(base_str[num % base], len);
}
