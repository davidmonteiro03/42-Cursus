/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:57:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 20:57:26 by dcaetano         ###   ########.fr       */
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
	wait_ms(philo->data->time_to_eat);
	philo->last_meal = ph_get_time();
	ph_leave_forks(philo);
}

void	ph_thinking(t_philo *philo)
{
	ph_status(philo, THINKING);
}

void	ph_sleeping(t_philo *philo)
{
	ph_status(philo, SLEEPING);
	wait_ms(philo->data->time_to_sleep);
}
