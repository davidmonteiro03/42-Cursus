/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:57:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/03 15:57:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ph_status(philo, FORK);
		pthread_mutex_lock(philo->right_fork);
		ph_status(philo, FORK);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ph_status(philo, FORK);
		pthread_mutex_lock(philo->left_fork);
		ph_status(philo, FORK);
	}
}

void	ph_leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ph_eating(t_philo *philo)
{
	ph_take_forks(philo);
	ph_status(philo, EATING);
	philo->last_meal = ph_get_time();
	ph_wait_ms(philo->data->time_to_eat);
	if (philo->data->num_of_meals_for_ph != -1 && \
		philo->num_of_meals < philo->data->num_of_meals_for_ph)
		philo->num_of_meals++;
	ph_leave_forks(philo);
}

void	ph_thinking(t_philo *philo)
{
	ph_status(philo, THINKING);
}

void	ph_sleeping(t_philo *philo)
{
	ph_status(philo, SLEEPING);
	ph_wait_ms(philo->data->time_to_sleep);
}
