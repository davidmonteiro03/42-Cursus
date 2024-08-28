/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:12:15 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 15:12:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthex(size_t hex, t_help *help)
{
	static const char	*base = "0123456789abcdef";

	if (help == NULL)
		return ;
	if (hex > 15)
	{
		puthex(hex / 16, help);
		puthex(hex % 16, help);
	}
	else
		ft_putchar(base[hex % 16], help);
}

void	ft_putptr(void *ptr, t_help *help)
{
	if (help == NULL)
		return ;
	if (ptr == NULL)
		return (ft_putstr("(nil)", help));
	ft_putstr("0x", help);
	puthex((size_t)ptr, help);
}
