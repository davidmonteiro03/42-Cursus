/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:55:48 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 10:24:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(size_t size, int *ret)
{
	const char	*base;

	base = "0123456789abcdef";
	if (size > 15)
	{
		ft_puthex(size / 16, ret);
		ft_puthex(size % 16, ret);
	}
	else
		ft_putchar(base[size % 16], ret);
}

void	ft_putptr(const void *ptr, int *ret)
{
	if (ptr != NULL)
		return (ft_putstr("0x", ret), ft_puthex((size_t)ptr, ret));
	*ret += write(1, "(nil)", 5);
}
