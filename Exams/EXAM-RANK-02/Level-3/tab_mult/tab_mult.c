/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:00:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/09/12 21:06:00 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	ft_putstr(char *str)
{
	if (str == 0)
		return ;
	while (*str)
		ft_putchar(*str++);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
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

int	main(int argc, char **argv)
{
	int	num;
	int	i;

	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		i = 0;
		while (i++ < 9)
		{
			if (i > 1)
				ft_putchar('\n');
			ft_putnbr(i);
			ft_putstr(" x ");
			ft_putnbr(num);
			ft_putstr(" = ");
			ft_putnbr(i * num);
		}
	}
	ft_putchar('\n');
	return (0);
}
