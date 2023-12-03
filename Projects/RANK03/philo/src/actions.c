/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:37:45 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/03 22:15:42 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_status(t_philo philo, char *status)
{
	if (pthread_mutex_lock(philo.data->display))
		return (1);
	printf("%5ld ms | %3d | %s\n", ph_get_time() - philo.data->start_time,
		philo.id, status);
	if (pthread_mutex_unlock(philo.data->display))
		return (1);
	return (0);
}

int	ph_eating(t_philo philo)
{
	pthread_mutex_lock(philo.right_fork);
	pthread_mutex_lock(philo.left_fork);
	if (ph_status(philo, FORK))
		return (pthread_mutex_unlock(philo.right_fork), \
			pthread_mutex_unlock(philo.left_fork), 1);
	if (ph_status(philo, EATING))
		return (pthread_mutex_unlock(philo.right_fork), \
			pthread_mutex_unlock(philo.left_fork), 1);
	philo.last_meal = ph_get_time();
	philo.meals_count++;
	usleep(philo.data->time_to_eat * 1000);
	return (pthread_mutex_unlock(philo.right_fork), \
		pthread_mutex_unlock(philo.left_fork), 0);
}

void	*ph_routine(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *)arg;
	while (1)
	{
		if (ph_eating(philo))
			return (NULL);
		if (ph_status(philo, SLEEPING))
			return (NULL);
		usleep(philo.data->time_to_sleep * 1000);
		if (ph_status(philo, THINKING))
			return (NULL);
	}
	return (NULL);
}

int	ph_execute(t_philo *philo, int i)
{
	if (philo[0].data->num_philos == 1)
	{
		philo[0].data->start_time = ph_get_time();
		usleep(philo[0].data->time_to_die * 1000);
		return (ph_status(philo[0], DIED), 0);
	}
	philo[0].data->start_time = ph_get_time();
	while (++i < philo[0].data->num_philos)
		if (pthread_create(&philo[i].thread, NULL, &ph_routine, &philo[i]))
			return (1);
	i = -1;
	while (++i < philo[0].data->num_philos)
		if (pthread_join(philo[i].thread, NULL))
			return (1);
	return (0);
}
