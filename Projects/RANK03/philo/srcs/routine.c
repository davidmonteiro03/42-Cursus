/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:19:01 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 13:21:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	thinking(t_ph *ph)
{
	status(ph, THINK);
}

void	sleeping(t_ph *ph)
{
	status(ph, SLEEP);
	usleep(ph->inf->time_sleep * 1000);
}
