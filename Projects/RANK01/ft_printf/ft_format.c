/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:54:45 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/06 19:54:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char c, int *len, va_list args)
{
	void	*ptr;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int), len));
	if (c == 's')
		return (ft_putstr(va_arg(args, char*), len));
	if (c == 'p')
	{
		ptr = va_arg(args, void*);
		if (!ptr)
			return (ft_putstr("(nil)", len));
		return (ft_putptr(ptr, len));
	}
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), len));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, len, c));
	if (ft_tolower(c) == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), 16, len, c));
	if (c == '%')
		return (ft_putchar('%', len));
}
