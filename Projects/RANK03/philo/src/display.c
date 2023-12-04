/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:25:28 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 17:31:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_display_status(t_philo *philo, char *status)
{
	if (pthread_mutex_lock(philo->data->display))
		return (1);
	printf("| %6ld ms | %8d | %-16s |\n", \
		ph_get_time() - philo->data->start_time, philo->id, status);
	return (pthread_mutex_unlock(philo->data->display), 0);
}

void	ph_display(bool start)
{
	if (start)
	{
		printf("+-----------+----------+------------------+\n");
		printf("| %9s | %8s | %-16s |\n", "TIMESTAMP", "PHILO ID", "STATUS");
	}
	printf("+-----------+----------+------------------+\n");
}
