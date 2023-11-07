/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:40:35 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 15:40:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_info(t_info *info, char **av)
{
	info->ttd = philo_atoi(av[2]) * 1000;
	info->tte = philo_atoi(av[3]) * 1000;
	info->tts = philo_atoi(av[4]) * 1000;
}

void	*philo_create(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	return (NULL);
}

void	create_philo(t_philo **philo, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		pthread_create(&philo[i]->id, NULL, philo_create, &philo[i]);
	}
}

void	join_philo(t_philo **philo, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		pthread_join(philo[i]->id, NULL);
}

void	free_philo(t_philo **philo, int num)
{
	int	i;

	if (!philo)
		return ;
	i = -1;
	while (++i < num)
		free(philo[i]);
	free(philo);
}
