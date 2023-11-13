/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:07:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 09:29:28 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_forks(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->num_ph)
		if (pthread_mutex_init(&inf->forks[i], NULL) != 0)
			return (1);
	return (0);
}

int	init_philos(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->num_ph)
	{
		inf->ph[i].ph_id = i;
		inf->ph[i].inf = inf;
		inf->ph[i].meal_count = 0;
		inf->ph[i].left_fork = &inf->forks[i];
		inf->ph[i].right_fork = &inf->forks[(i + 1) % inf->num_ph];
	}
	return (0);
}

int	init_inf(t_inf *inf, int ac, char **av)
{
	inf->num_ph = ph_atoi(av[1]);
	inf->time_die = ph_atoi(av[2]);
	inf->time_eat = ph_atoi(av[3]);
	inf->time_sleep = ph_atoi(av[4]);
	inf->num_time_meals_ph = -1;
	if (ac == 6)
		inf->num_time_meals_ph = ph_atoi(av[5]);
	inf->forks = (t_mutex *)malloc(sizeof(t_mutex) * inf->num_ph);
	if (!inf->forks)
		return (clean_all(inf, 0), 1);
	if (init_forks(inf) != 0)
		return (clean_all(inf, 1), 1);
	inf->ph = (t_ph *)malloc(sizeof(t_ph) * inf->num_ph);
	if (!inf->ph)
		return (clean_all(inf, 2), 1);
	init_philos(inf);
	inf->th = (t_th *)malloc(sizeof(t_th) * inf->num_ph);
	if (!inf->th)
		return (clean_all(inf, 3), 1);
	return (0);
}
