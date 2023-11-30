/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:50:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 19:37:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ph_atol(const char *str)
{
	long	num;
	size_t	i;

	num = 0;
	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	return (num);
}

int	ph_check(int i, char **av)
{
	int	j;

	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
		if (ph_atol(av[i]) > 2147483647 || ph_atol(av[i]) <= 0)
			return (1);
	}
	return (0);
}
