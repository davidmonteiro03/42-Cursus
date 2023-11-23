/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:33:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 10:54:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ph_status(t_ph *ph, char *status)
{
	long	time;

	pthread_mutex_lock(ph->inf->print);
	if (ph->last_meal == -1)
		time = get_time() - ph->inf->start_time;
	else
		time = get_time() - ph->last_meal;
	printf("%ld %d %s\n", time, ph->ph_num, status);
	pthread_mutex_unlock(ph->inf->print);
}
