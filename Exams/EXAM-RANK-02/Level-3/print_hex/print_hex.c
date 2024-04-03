/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:36:39 by dcaetano          #+#    #+#             */
/*   Updated: 2024/04/03 12:42:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_atou(const char *str)
{
	unsigned int	res;

	res = 0;
	while (*str && *str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(unsigned int nbr, unsigned int size)
{
	const char	*base;

	base = "0123456789abcdef";
	if (nbr > size - 1)
	{
		ft_putnbr_base(nbr / size, size);
		ft_putnbr_base(nbr % size, size);
	}
	else
		ft_putchar(base[nbr % size]);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr_base(ft_atou(argv[1]), 16);
	ft_putchar('\n');
	return (0);
}
