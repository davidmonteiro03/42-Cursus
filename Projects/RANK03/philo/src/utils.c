/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uts.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:37:55 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 19:35:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ph_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	wait_ms(long long time)
{
	long long	start;

	start = ph_get_time();
	while ((ph_get_time() - start) < time)
		usleep(1);
}
