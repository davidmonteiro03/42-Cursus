/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:45:08 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/09 19:18:27 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	*len += write(1, &c, 1);
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
		*len += write(1, "(null)", 6);
	else
		while (*str)
			ft_putchar(*str++, len);
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
		ft_putchar(n + '0', len);
}

void	ft_puthex(unsigned int n, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
	{
		ft_puthex(n / 16, len);
		ft_puthex(n % 16, len);
	}
	else
		ft_putchar(hex[n % 16], len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(args, char *), &len);
			else if (*format == 'd')
				ft_putnbr(va_arg(args, int), &len);
			else if (*format == 'x')
				ft_puthex(va_arg(args, unsigned int), &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
