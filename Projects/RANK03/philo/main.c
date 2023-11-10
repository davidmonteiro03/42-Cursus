/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/10 16:33:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo_1(t_inf *inf)
{
	status(&inf->ph[0], "is thinking");
	usleep(inf->time_die * 1000);
	status(&inf->ph[0], "died");
}

void	*routine(void *philo)
{
	t_ph	*ph;

	ph = (t_ph *)philo;
	while (1)
	{
		status(ph, "is thinking");
		lock_forks(ph);
		status(ph, "is eating");
		usleep(ph->inf->time_eat * 1000);
		unlock_forks(ph);
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
