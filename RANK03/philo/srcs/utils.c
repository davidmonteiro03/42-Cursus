/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:06:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 10:26:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	wait_ms(int us)
{
	usleep(us * 1000);
}

void	status(t_ph *ph, char *info)
{
	printf("%lu %d", get_time() - ph->inf->st, ph->n);
	printf(" %s\n", info);
}
