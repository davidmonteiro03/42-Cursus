/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:58:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 09:18:38 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_eating(t_philo *philo)
{
	t_mutex	*first;
	t_mutex	*last;

	first = philo->right_fork;
	last = philo->left_fork;
	if (philo->id % 2 == 0)
	{
		first = philo->left_fork;
		last = philo->right_fork;
	}
	pthread_mutex_lock(first);
	pthread_mutex_lock(last);
	if (ph_display_status(philo, FORK))
		return (pthread_mutex_unlock(first), pthread_mutex_unlock(last), 1);
	if (ph_display_status(philo, EATING))
		return (pthread_mutex_unlock(first), pthread_mutex_unlock(last), 1);
	philo->last_meal = ph_get_time();
	usleep(philo->data->time_to_eat * 1000);
	philo->meals_count++;
	return (pthread_mutex_unlock(first), pthread_mutex_unlock(last), 0);
}

bool	ph_check_for_deaths(t_philo *philo)
{
	long	now;

	now = ph_get_time();
	if ((philo->last_meal == -1 && \
		now - philo->data->start_time > philo->data->time_to_die) || \
		(philo->last_meal != -1 && \
		now - philo->last_meal > philo->data->time_to_die))
	{
		ph_display_status(philo, DIED);
		return (true);
	}
	return (false);
}

void	*ph_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ph_display_status(philo, THINKING))
			return (NULL);
		if (ph_check_for_deaths(philo))
			break ;
		if (ph_eating(philo))
			return (NULL);
		if (ph_display_status(philo, SLEEPING))
			return (NULL);
		usleep(philo->data->time_to_sleep * 1000);
	}
	return (NULL);
}

int	ph_execute(t_philo *philo, int i)
{
	if (!philo)
		return (1);
	if (philo->data->num_philos == 1)
	{
		ph_display(true);
		philo->data->start_time = ph_get_time();
		usleep(philo->data->time_to_die * 1000);
		return (ph_display_status(philo, DIED), ph_display(false), 0);
	}
	philo->data->start_time = ph_get_time();
	ph_display(true);
	while (++i < philo->data->num_philos)
		if (pthread_create(&philo[i].thread, NULL, &ph_routine, &philo[i]))
			break ;
	i = -1;
	while (++i < philo->data->num_philos)
		if (pthread_join(philo[i].thread, NULL))
			break ;
	return (ph_display(false), 0);
}
