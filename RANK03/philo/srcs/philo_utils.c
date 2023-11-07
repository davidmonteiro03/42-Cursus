/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:25:13 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 19:33:37 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	return ((ct.tv_sec * 1000) + (ct.tv_usec / 1000));
}

void	philo_waitms(int ms)
{
	usleep(ms * 1000);
}

void	display_status(t_philo *philo, char *action)
{
	printf("%ld %d", get_time() - philo->info->st, philo->n);
	printf(" %s\n", action);
}
