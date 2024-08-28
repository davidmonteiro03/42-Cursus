/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:13:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 15:34:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *format, va_list args, t_help *help)
{
	if (format == NULL || args == NULL || help == NULL)
		return ;
	if (format[help->i] == '%')
		ft_putchar('%', help);
	else if (format[help->i] == 'c')
		ft_putchar(va_arg(args, int), help);
	else if (format[help->i] == 's')
		ft_putstr(va_arg(args, char *), help);
	else if (format[help->i] == 'p')
		ft_putptr(va_arg(args, void *), help);
	else if (format[help->i] == 'd' || format[help->i] == 'i')
		ft_putnbr(va_arg(args, int), help);
	else if (format[help->i] == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), 10, 0, help);
	else if (format[help->i] == 'x' || format[help->i] == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), 16, format[help->i] == 'X',
			help);
}
