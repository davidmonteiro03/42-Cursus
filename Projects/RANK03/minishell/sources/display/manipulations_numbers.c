/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulations_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:42:33 by preis-ne          #+#    #+#             */
/*   Updated: 2024/09/06 09:24:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	display_number(const char *str, t_tmp *tmp, int *j)
{
	int	d;
	int	f;
	int	n;
	int	g;

	g = 0;
	d = 0;
	f = 1;
	n = 0;
	while (ft_isdigit(str[tmp->i + *j + g]) != 0)
		g++;
	d = g;
	while (g-- > 1)
		f = f * 10;
	while (d > 0)
	{
		n = n + ((str[tmp->i + *j + g] - '0') * f);
		f /= 10;
		g++;
		d--;
	}
	return (n);
}

void	display_putnbr(long n, t_tmp *tmp)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		display_putnbr((n / 10), tmp);
	display_putchar_len((n % 10 + '0'), tmp);
}

void	display_putnbr_base(unsigned long long int nb, t_tmp *tmp, char *base)
{
	unsigned long long int	basen;

	basen = ft_strlen(base);
	if (nb >= basen)
		display_putnbr_base(nb / basen, tmp, base);
	display_putchar_len(base[nb % basen], tmp);
}

void	display_putnbr_base_x(unsigned int nb, t_tmp *tmp, char *base)
{
	unsigned int	basen;

	basen = ft_strlen(base);
	if (nb >= basen)
		display_putnbr_base(nb / basen, tmp, base);
	display_putchar_len(base[nb % basen], tmp);
}

void	display_putnbr_unsigned(unsigned int n, t_tmp *tmp)
{
	if (n >= 10)
		display_putnbr_unsigned((n / 10), tmp);
	display_putchar_len((n % 10 + '0'), tmp);
}
