/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:14:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/06 19:58:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			ft_format(*(++format), &ret, args);
		else
			ft_putchar(*format, &ret);
		format++;
	}
	va_end(args);
	return (ret);
}
