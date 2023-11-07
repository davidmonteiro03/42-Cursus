/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:36:09 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 13:38:52 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_create(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	return (NULL);
}

void	create_philos(t_philo *philo, t_info info, int np)
{
	int	i;

	i = -1;
	while (++i < np)
	{
		philo[i].info = info;
		pthread_create(&philo[i].id, NULL, philo_create, &philo[i]);
	}
}

void	join_philos(t_philo *philo, int np)
{
	int	i;

	i = -1;
	while (++i < np)
		pthread_join(philo[i].id, NULL);
}
