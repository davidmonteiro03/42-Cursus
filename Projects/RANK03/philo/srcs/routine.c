/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:24:42 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 18:28:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	lock_forks(t_ph *ph)
{
	pthread_mutex_lock(ph->lf);
	status(ph, FORK);
	pthread_mutex_lock(ph->rf);
	status(ph, FORK);
}

static void	unlock_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->lf);
	pthread_mutex_unlock(ph->rf);
}

void	thinking(t_ph *ph)
{
	status(ph, THINK);
}

void	eating(t_ph *ph)
{
	lock_forks(ph);
	status(ph, EAT);
	usleep(ph->inf->time_eat * 1000);
	ph->meal_count++;
	ph->lm = gettime();
	unlock_forks(ph);
}

void	sleeping(t_ph *ph)
{
	status(ph, SLEEP);
	usleep(ph->inf->time_sleep * 1000);
}
