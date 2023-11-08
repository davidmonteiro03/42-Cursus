/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:54:37 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 14:57:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_forks(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->np)
		pthread_mutex_init(&inf->f[i], NULL);
}

void	init_philos(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->np)
	{
		inf->ph[i].inf = inf;
		inf->ph[i].n = i + 1;
		inf->ph[i].lf = &inf->f[i];
		inf->ph[i].rf = &inf->f[(i + 1) % inf->np];
		inf->ph[i].lm = -1;
	}
}

void	init_inf(t_inf *inf, int ac, char **av)
{
	inf->np = ph_atol(av[1]);
	inf->ttd = ph_atol(av[2]);
	inf->tte = ph_atol(av[3]);
	inf->tts = ph_atol(av[4]);
	inf->notepme = -1;
	if (ac == 6)
		inf->notepme = ph_atol(av[5]);
	inf->f = (t_f *)malloc(sizeof(t_f) * inf->np);
	inf->id = (t_id *)malloc(sizeof(t_id) * inf->np);
	inf->ph = (t_ph *)malloc(sizeof(t_ph) * inf->np);
}
