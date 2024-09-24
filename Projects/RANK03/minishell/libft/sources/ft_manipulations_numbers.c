/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manipulations_numbers_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preis-ne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:42:33 by preis-ne          #+#    #+#             */
/*   Updated: 2024/01/04 06:33:15 by preis-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_number(const char *str, int *i, int *j)
{
	int	d;
	int	f;
	int	n;
	int	g;

	g = 0;
	d = 0;
	f = 1;
	n = 0;
	while (ft_isdigit(str[*i + *j + g]) != 0)
		g++;
	d = g;
	while (g-- > 1)
		f = f * 10;
	while (d > 0)
	{
		n = n + ((str[*i + *j + g] - '0') * f);
		f /= 10;
		g++;
		d--;
	}
	return (n);
}

void	ft_putnbr(long n, int *len)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_putnbr((n / 10), len);
	ft_putchar_len((n % 10 + '0'), len);
}

void	ft_putnbr_unsigned(unsigned int n, int *len)
{
	if (n >= 10)
		ft_putnbr_unsigned((n / 10), len);
	ft_putchar_len((n % 10 + '0'), len);
}

void	ft_putnbr_base_x(unsigned int nb, int *len, char *base)
{
	unsigned int	basen;

	basen = ft_strlen(base);
	if (nb >= basen)
		ft_putnbr_base(nb / basen, len, base);
	ft_putchar_len(base[nb % basen], len);
}

void	ft_putnbr_base(unsigned long long int nb, int *len, char *base)
{
	unsigned long long int	basen;

	basen = ft_strlen(base);
	if (nb >= basen)
		ft_putnbr_base(nb / basen, len, base);
	ft_putchar_len(base[nb % basen], len);
}
