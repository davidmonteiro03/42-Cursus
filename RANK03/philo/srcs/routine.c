/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:00:13 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 15:28:59 by dcaetano         ###   ########.fr       */
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

void	unlock_forks(t_ph *ph)
{
	pthread_mutex_unlock(ph->lf);
	pthread_mutex_unlock(ph->rf);
}
