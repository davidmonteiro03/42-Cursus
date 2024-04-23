/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 09:18:10 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/23 09:34:46 by dcaetano         ###   ########.fr       */
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
}
