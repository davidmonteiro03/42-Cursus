/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:17:43 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 21:55:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_help	help;

	va_start(args, format);
	help = (t_help){.fd = STDOUT_FILENO, .i = 0, .len = 0};
	while (format[help.i] != '\0')
	{
		if (format[help.i] == '%')
		{
			help.i++;
			ft_format_bonus(format, args, &help);
			if (format[help.i] != '\0')
				help.i++;
			continue ;
		}
		while (format[help.i] != '\0' && format[help.i] != '%')
			ft_putchar(format[help.i++], &help);
	}
	va_end(args);
	return (help.len);
}
