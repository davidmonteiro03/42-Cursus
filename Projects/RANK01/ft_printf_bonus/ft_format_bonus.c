/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:13:19 by dcaetano          #+#    #+#             */
/*   Updated: 2024/08/28 23:01:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isflag(int c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}

void	ft_format_bonus(const char *format, va_list args, t_help *help)
{
	if (format == NULL || args == NULL || help == NULL)
		return ;
	while (format[help->i] != '\0' && isflag(format[help->i]) != 0)
		ft_putchar(format[help->i++], help);
}
