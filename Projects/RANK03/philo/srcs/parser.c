/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:14:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/24 14:09:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ph_num(const char *p)
{
	long	n;
	long	s;
	size_t	i;

	n = 0;
	s = 1;
	i = 0;
	while (p[i] == 32 || (p[i] >= 9 && p[i] <= 13))
		i++;
	if (p[i] == '+' || p[i] == '-')
		if (p[i++] == '-')
			s = -1;
	while (p[i] && p[i] >= '0' && p[i] <= '9')
		n = n * 10 + p[i++] - '0';
	return (n * s);
}

int	ph_inv(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[++i])
	{
		j = -1;
		while (v[i][++j])
			if (v[i][j] < '0' || v[i][j] > '9')
				return (1);
	}
	return (0);
}

int	ph_rng(char **v)
{
	int		i;
	long	n;

	i = 0;
	while (v[++i])
	{
		n = ph_num(v[i]);
		if (n < 1 || n > 2147483647)
			return (1);
	}
	return (0);
}
