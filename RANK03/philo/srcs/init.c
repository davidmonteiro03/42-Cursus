/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:11:04 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 10:40:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_inf(t_inf *inf, int ac, char **av)
{
	inf->np = ph_atoi(av[1]);
	inf->ttd = ph_atoi(av[2]) * 1000;
	inf->tte = ph_atoi(av[3]) * 1000;
	inf->tts = ph_atoi(av[4]) * 1000;
	inf->notepme = -1;
	inf->die = false;
	if (ac == 6)
		inf->notepme = ph_atoi(av[5]);
	inf->ph = (t_ph *)malloc(sizeof(t_ph) * inf->np);
}

void	init_philos(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->np)
	{
		inf->ph[i].n = i + 1;
		inf->ph[i].inf = inf;
	}
}
