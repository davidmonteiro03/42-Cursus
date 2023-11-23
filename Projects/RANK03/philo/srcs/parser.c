/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:14:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 09:35:30 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	ph_check_arg(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
	return (0);
}

long	ph_atol(const char *nptr)
{
	long	num;
	long	sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	return (num * sign);
}

int	ph_parse_args(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
		if (ph_check_arg(av[i]))
			return (1);
	return (0);
}

int	ph_parse_range(char **av)
{
	int		i;
	long	tmp;

	i = 0;
	while (av[++i])
	{
		tmp = ph_atol(av[i]);
		if (tmp < 1 || tmp > 2147483647)
			return (1);
	}
	return (0);
}
