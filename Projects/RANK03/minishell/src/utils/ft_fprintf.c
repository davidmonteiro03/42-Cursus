/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:06:01 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 16:44:55 by dflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_fputchar(int fd, char c, int *len)
{
	*len += write(fd, &c, 1);
}

static void	ft_fputstr(int fd, char *str, int *len)
{
	if (!str)
		*len += write(fd, "(null)", 6);
	else
		while (*str)
			ft_fputchar(fd, *str++, len);
}

static void	ft_fputnbr(int fd, int num, int *len)
{
	if (num == -2147483648)
	{
		ft_fputstr(fd, "-2147483648", len);
		return ;
	}
	if (num < 0)
	{
		ft_fputchar(fd, '-', len);
		num = -num;
	}
	if (num > 9)
	{
		ft_fputnbr(fd, num / 10, len);
		ft_fputnbr(fd, num % 10, len);
	}
	else
		ft_fputchar(fd, num + '0', len);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_fputchar(fd, va_arg(args, int), &len);
			else if (*format == 's')
				ft_fputstr(fd, va_arg(args, char *), &len);
			else if (*format == 'd')
				ft_fputnbr(fd, va_arg(args, int), &len);
		}
		else
			ft_fputchar(fd, *format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
