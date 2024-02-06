/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:14:41 by dcaetano          #+#    #+#             */
/*   Updated: 2024/02/06 19:49:47 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

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

void	ft_putnbr(int num, int *len)
{
	if (num == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (num < 0)
	{
		ft_putchar('-', len);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, len);
		ft_putnbr(num % 10, len);
	}
	else
		ft_putchar(num + '0', len);
}

void	ft_putnbr_base(unsigned int num, unsigned int base, int *len, char caps)
{
	char	*base_str;

	if (caps == ft_tolower(caps))
		base_str = "0123456789abcdef";
	else
		base_str = "0123456789ABCDEF";
	if (num > base - 1)
	{
		ft_putnbr_base(num / base, base, len, caps);
		ft_putnbr_base(num % base, base, len, caps);
	}
	else
		ft_putchar(base_str[num % base], len);
}

size_t	ft_len(size_t n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len + 2);
}

char	*ft_converthex(size_t num, size_t size)
{
	char	*base;
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	base = "0123456789abcdef";
	while (num > 0 && size > 1)
	{
		str[size--] = base[num % 16];
		num /= 16;
	}
	str[1] = 'x';
	str[0] = '0';
	return (str);
}

void	ft_putptr(void *ptr, int *len)
{
	char	*str;

	str = ft_converthex((size_t)ptr, ft_len((size_t)ptr));
	if (!str)
		return ;
	return (ft_putstr(str, len), free(str));
}

void	check_format(char c, int *len, va_list args)
{
	void	*ptr;

	if (c == 'c')
		return (ft_putchar(va_arg(args, int), len));
	if (c == 's')
		return (ft_putstr(va_arg(args, char*), len));
	if (c == 'p')
	{
		ptr = va_arg(args, void*);
		if (!ptr)
			return (ft_putstr("(nil)", len));
		return (ft_putptr(ptr, len));
	}
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), len));
	if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), 10, len, c));
	if (ft_tolower(c) == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), 16, len, c));
	if (c == '%')
		return (ft_putchar('%', len));
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	args;

	ret = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			check_format(*(++format), &ret, args);
		else
			ft_putchar(*format, &ret);
		format++;
	}
	va_end(args);
	return (ret);
}
