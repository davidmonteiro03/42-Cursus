/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/10 17:47:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo_1(t_inf *inf)
{
	status(&inf->ph[0], "is thinking");
	usleep(inf->time_die * 1000);
	status(&inf->ph[0], "died");
}

void	peace(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->num_ph)
		pthread_mutex_destroy(&inf->f[i]);
	if (inf->f)
		free(inf->f);
	if (inf->ph)
		free(inf->ph);
	if (inf->th)
		free(inf->th);
}

void	*routine(void *philo)
{
	t_ph	*ph;
	long	cur;

	ph = (t_ph *)philo;
	while (!ph->inf->end)
	{
		status(ph, "is thinking");
		if (lock_forks(ph) == 0)
		{
			status(ph, "is eating");
			ph->inf->cur_eat++;
			cur = get_time();
			if (ph->lm != -1 && cur > ph->lm)
			{
				status(ph, "died");
				ph->inf->end = true;
			}
			if (ph->inf->num_times_ph_eat != -1 && \
				ph->meal_count >= ph->inf->num_times_ph_eat)
				ph->inf->end = true;
			usleep(ph->inf->time_eat * 1000);
			unlock_forks(ph);
			ph->inf->cur_eat--;
		}
		sleeping(ph);
	}
	return (NULL);
}

void	confusion(t_inf *inf)
{
	int	i;

	inf->st = get_time();
	if (inf->num_ph == 1)
		return (philo_1(inf));
	i = -1;
	while (++i < inf->num_ph)
		pthread_create(&inf->th[i], NULL, &routine, &inf->ph[i]);
	inf->st = get_time();
	i = -1;
	while (++i < inf->num_ph)
		pthread_join(inf->th[i], NULL);
}

int	main(int ac, char **av)
{
	t_inf	inf;

	if (ac != 5 && ac != 6)
		error_usage(ac, av);
	check_args(ac, av);
	init_inf(&inf, ac, av);
	init_forks(&inf);
	init_philos(&inf);
	display_start();
	confusion(&inf);
	display_end();
	peace(&inf);
	return (0);
}
