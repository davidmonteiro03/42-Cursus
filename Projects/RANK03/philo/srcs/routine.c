/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:59:40 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/16 18:44:40 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock_forks(t_ph *ph)
{
	pthread_mutex_lock(ph->lf);
	status(ph, FORK);
	pthread_mutex_lock(ph->rf);
	status(ph, FORK);
}

void	unlock_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->rf);
	pthread_mutex_unlock(ph->lf);
}

void	eat(t_ph *ph)
{
	lock_forks(ph);
	pthread_mutex_lock(ph->inf->action_lock);
	status(ph, EAT);
	ph->lm = gettime();
	usleep(ph->inf->time_eat * 1000);
	if (ph->inf->num_meals_ph != -1 && ph->meal_count < ph->inf->num_meals_ph)
		ph->meal_count++;
	pthread_mutex_unlock(ph->inf->action_lock);
	unlock_forks(ph);
}

void	think(t_ph *ph)
{
	status(ph, THINK);
}

void	sleeping(t_ph *ph)
{
	status(ph, SLEEP);
	usleep(ph->inf->time_sleep * 1000);
}
