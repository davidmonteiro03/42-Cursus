/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:39:25 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 14:00:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_deads(t_inf **inf)
{
	int	i;
	int	deads;

	deads = 0;
	i = -1;
	while (++i < (*inf)->num_ph)
		if ((*inf)->ph[i].dead)
			deads++;
	return (deads);
}

long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	status(t_ph *ph, char *status)
{
	if (check_deads(&ph->inf))
		return ;
	pthread_mutex_lock(ph->inf->action_lock);
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
	pthread_mutex_unlock(ph->inf->action_lock);
}
