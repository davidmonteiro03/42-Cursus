/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:58:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 19:13:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_forks(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->np)
		pthread_mutex_init(&info->f[i], NULL);
}

void	init_philos(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->np)
	{
		info->ph[i].n = i + 1;
		info->ph[i].info = info;
		info->ph[i].ec = 0;
		info->ph[i].lm = -1;
		info->ph[i].lf = &info->f[i];
		info->ph[i].rf = &info->f[(i + 1) % info->np];
	}
}

void	init_info(t_info *info, int ac, char **av)
{
	info->np = philo_atoi(av[1]);
	info->ttd = philo_atoi(av[2]);
	info->tte = philo_atoi(av[3]);
	info->tts = philo_atoi(av[4]);
	info->die = false;
	info->notepme = -1;
	if (ac == 6)
		info->notepme = philo_atoi(av[5]);
	info->th = (pthread_t *)malloc(sizeof(pthread_t) * info->np);
	info->f = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->np);
	info->ph = (t_philo *)malloc(sizeof(t_philo) * info->np);
}
