/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:58:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 17:08:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_small_data_update(t_philo *philo)
{
	philo->meals_count++;
	pthread_mutex_lock(&philo->data->check);
	if (philo->meals_count == philo->data->num_meals_per_philo)
	{
		philo->done = true;
		philo->data->num_finish_meals++;
	}
	pthread_mutex_unlock(&philo->data->check);
}

int	ph_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ph_display_status(philo, FORK);
	if (pthread_mutex_lock(philo->left_fork))
		return (pthread_mutex_unlock(philo->right_fork), 1);
	if (ph_display_status(philo, FORK))
		return (pthread_mutex_unlock(philo->right_fork), \
			pthread_mutex_unlock(philo->left_fork), 1);
	if (ph_display_status(philo, EATING))
		return (pthread_mutex_unlock(philo->right_fork), \
			pthread_mutex_unlock(philo->left_fork), 1);
	philo->last_meal = ph_get_time();
	usleep(philo->data->time_to_eat * 1000);
	if (philo->meals_count < philo->data->num_meals_per_philo)
		ph_small_data_update(philo);
	return (pthread_mutex_unlock(philo->right_fork), \
		pthread_mutex_unlock(philo->left_fork), 0);
}

void	*ph_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (ph_display_status(philo, THINKING))
			return (NULL);
		if (ph_eating(philo))
			return (NULL);
		if (ph_check_finish_meals(philo))
			break ;
		if (ph_display_status(philo, SLEEPING))
			return (NULL);
		if (ph_check_deaths(philo))
			break ;
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
