/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:50:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 12:59:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ph_num(const char *s)
{
	long	n;
	size_t	i;

	n = 0;
	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		n = n * 10 + s[i++] - '0';
	return (n);
}

int	ph_chk(int i, char **v)
{
	int	j;

	while (v[++i])
	{
		j = -1;
		while (v[i][++j])
			if (v[i][j] < '0' || v[i][j] > '9')
				return (1);
		if (ph_num(v[i]) > 2147483647 || ph_num(v[i]) <= 0)
			return (1);
	}
	return (0);
}
