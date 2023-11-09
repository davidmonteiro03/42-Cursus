/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:27:46 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/09 10:11:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	display_start(void)
{
	printf("+------------+----------+------------------+\n");
	printf("| %-10s | %-8s | %-16s |\n", "TIMESTAMP", "N_PHILO", "STATUS");
	printf("+------------+----------+------------------+\n");
}

void	display_end(void)
{
	printf("+------------+----------+------------------+\n");
}
