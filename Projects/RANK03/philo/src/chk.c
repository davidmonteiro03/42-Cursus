/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:50:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/25 16:59:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ph_num(const char *s)
{
	long	n;

	n = 0;
	while (*s)
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n);
}

int	ph_chk(char **v)
{
	while (*v)
	{
		while (**v)
		{
			if (**v < '0' || **v > '9')
				return (1);
			if (ph_num(*v) > 2147483647 || ph_num(*v) <= 0)
				return (1);
			(*v)++;
		}
		v++;
	}
	return (0);
}
