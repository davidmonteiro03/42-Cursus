/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:32:33 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 10:52:26 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_lock_f(t_ph *ph)
{
	pthread_mutex_lock(&ph->inf->forks[ph->ph_num - 1]);
	ph_status(ph, FORK);
	pthread_mutex_lock(&ph->inf->forks[ph->ph_num % ph->inf->num_ph]);
	ph_status(ph, FORK);
}

void	ph_unlock_f(t_ph *ph)
{
	pthread_mutex_unlock(&ph->inf->forks[ph->ph_num - 1]);
	pthread_mutex_unlock(&ph->inf->forks[ph->ph_num % ph->inf->num_ph]);
}

void	ph_eating(t_ph *ph)
{
	ph_lock_f(ph);
	ph_status(ph, EAT);
	ph->last_meal = get_time();
	usleep(ph->inf->time_eat * 1000);
	ph_unlock_f(ph);
}
