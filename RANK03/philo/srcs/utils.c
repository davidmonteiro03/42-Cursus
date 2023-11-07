/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:10:21 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 12:03:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	philo_atol(const char *nptr)
{
	int			sign;
	int			i;
	long int	num;

	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	if (!nptr[i])
		return (-2147483649);
	num = 0;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	if (nptr[i])
		return (-2147483649);
	return (num * sign);
}

void	philo_info(t_info *info, char **av)
{
	info->ttd = philo_atol(av[2]);
	info->tte = philo_atol(av[3]);
	info->tts = philo_atol(av[4]);
}

void	info_range(t_info info, int np)
{
	if (np < 0 || np > 2147483647 || \
		info.ttd < 0 || info.ttd > 2147483647 || \
		info.tte < 0 || info.tte > 2147483647 || \
		info.tts < 0 || info.tts > 2147483647)
		exit(EXIT_FAILURE);
}
