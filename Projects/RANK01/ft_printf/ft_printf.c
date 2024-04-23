/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 08:04:03 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 09:30:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	va_start(args, format);
	va_end(args);
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ft_format(++format, args, &ret);
			format++;
			continue ;
		}
		ft_putchar(*format++, &ret);
	}
	return (ret);
}
