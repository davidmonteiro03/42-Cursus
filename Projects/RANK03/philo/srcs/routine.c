/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:00:53 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/10 16:04:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock_forks(t_ph *ph)
{
	pthread_mutex_lock(ph->lf);
	status(ph, "has taken a fork");
	pthread_mutex_lock(ph->rf);
	status(ph, "has taken a fork");
}

void	sleeping(t_ph *ph)
{
	status(ph, "is sleeping");
	usleep(ph->inf->time_sleep);
}

void	unlock_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->lf);
	pthread_mutex_unlock(ph->rf);
	ph->meal_count++;
}
