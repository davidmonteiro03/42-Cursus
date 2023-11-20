/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:39:25 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 18:56:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_1(t_inf **inf)
{
	(*inf)->time_start = gettime();
	status((*inf)->ph, THINK);
	usleep((*inf)->time_die * 1000);
	status((*inf)->ph, DIED);
}

long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	status(t_ph *ph, char *status)
{
	if (ph->lm == -1)
	{
		printf("| %9ldms | %-5d | %-25s |\n", \
			(gettime() - ph->inf->time_start) / 1000, \
			ph->ph_id, \
			status \
		);
	}
	else
	{
		printf("| %9ldms | %-5d | %-25s |\n", \
			(gettime() - ph->lm) / 1000, \
			ph->ph_id, \
			status \
		);
	}
}
