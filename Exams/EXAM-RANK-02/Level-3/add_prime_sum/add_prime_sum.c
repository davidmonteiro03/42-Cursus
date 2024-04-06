/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:35:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/06 16:48:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (*str && *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str && *str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - '0');
	return (ret * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
		ft_putchar(nbr % 10 + '0');
}

int	ft_isprime(int nbr)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (i++ < nbr)
		if (nbr % i == 0)
			t++;
	return (t == 2);
}

void	add_prime_sum(int *result, int nbr)
{
	int	i;

	if (nbr <= 0)
		return ;
	i = 0;
	while (i++ < nbr)
	{
		if (!ft_isprime(i))
			continue ;
		*result += i;
	}
}

int	main(int argc, char **argv)
{
	int	num;

	num = 0;
	if (argc == 2)
		add_prime_sum(&num, ft_atoi(argv[1]));
	ft_putnbr(num);
	write(1, "\n", 1);
	return (0);
}
