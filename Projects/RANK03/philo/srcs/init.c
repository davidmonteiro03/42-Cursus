/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:40:35 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/10 15:49:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_forks(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->num_ph)
		pthread_mutex_init(&inf->f[i], NULL);
}

void	init_inf(t_inf *inf, int ac, char **av)
{
	inf->num_ph = ph_atol(av[1]);
	inf->time_die = ph_atol(av[2]);
	inf->time_eat = ph_atol(av[3]);
	inf->time_sleep = ph_atol(av[4]);
	inf->num_times_ph_eat = -1;
	if (ac == 6)
		inf->num_times_ph_eat = ph_atol(av[6]);
	inf->ph = (t_ph *)malloc(sizeof(t_ph) * inf->num_ph);
	inf->f = (t_f *)malloc(sizeof(t_f) * inf->num_ph);
	inf->th = (t_id *)malloc(sizeof(t_id) * inf->num_ph);
}

void	init_philos(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->num_ph)
	{
		inf->ph[i].id = i + 1;
		inf->ph[i].inf = inf;
		inf->ph[i].lf = &inf->f[i];
		inf->ph[i].lf = &inf->f[(i + 1) % inf->num_ph];
	}
}
