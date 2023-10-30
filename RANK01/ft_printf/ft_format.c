/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:12:56 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/07 15:55:11 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar((va_arg(args, int))));
	else if (format == 's')
		return (ft_putstr((va_arg(args, char *))));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_putptr(ptr));
		return (write(1, "(nil)", 5));
	}
	else if (format == 'i' || format == 'd')
		return (ft_putnbr((va_arg(args, int))));
	else if (format == 'u')
		return (ft_putnbru((va_arg(args, unsigned int))));
	else if (format == 'x' || format == 'X')
		return (ft_putstrhex((va_arg(args, unsigned int)), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}
