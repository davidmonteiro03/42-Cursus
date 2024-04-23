/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:18:10 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 11:12:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *format, va_list args, int *ret)
{
	if (format == NULL || *format == '\0')
		return ;
	if (*format == 'c')
		return (ft_putchar(va_arg(args, int), ret));
	if (*format == 's')
		return (ft_putstr(va_arg(args, char *), ret));
	if (*format == 'p')
		return (ft_putptr(va_arg(args, void *), ret));
	if (*format == 'd' || *format == 'i')
		return (ft_putnbr(va_arg(args, int), ret));
	if (*format == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, \
			ret, NULL));
	if (*format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), 16, \
			ret, &ft_tolower));
	if (*format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), 16, \
			ret, &ft_toupper));
}
