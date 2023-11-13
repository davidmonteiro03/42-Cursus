/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:57:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/11 18:31:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	check_number(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

int	ph_atoi(const char *str)
{
	unsigned long long int	num;

	num = 0;
	while (*str && *str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	if (num > 2147483647)
		return (-1);
	return ((int)num);
}

bool	check_args(int ac, char **av)
{
	int	i;
	int	num;

	i = 0;
	while (++i < ac)
	{
		if (!check_number(av[i]))
			return (false);
		num = ph_atoi(av[i]);
		if (i == 1 && num <= 0)
			return (false);
		if (i != -1 && num == -1)
			return (false);
	}
	return (true);
}
