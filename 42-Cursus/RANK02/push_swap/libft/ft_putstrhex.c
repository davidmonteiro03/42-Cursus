/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:01:48 by dcaetano          #+#    #+#             */
/*   Updated: 2023/10/06 20:34:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *x, unsigned int number, long int len, \
	const char format)
{
	char	*base;

	base = "0123456789abcdef";
	while (number > 0)
	{
		x[len--] = base[number % 16];
		if (format == 'X')
			x[len + 1] = ft_toupper(x[len + 1]);
		number = number / 16;
	}
	return (x);
}

static long int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_putstrhex(unsigned int n, const char format)
{
	char			*x;
	long int		len;
	unsigned int	number;
	int				num;

	len = ft_len(n);
	x = (char *)malloc(sizeof(char) * (len + 1));
	if (!x)
		return (0);
	x[len--] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
		number = n * -1;
	else
		number = n;
	num = ft_putstr(ft_array(x, number, len, format));
	free(x);
	return (num);
}
