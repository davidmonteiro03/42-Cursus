/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:25:28 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 15:49:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_display_status(t_philo *philo, char *status)
{
	bool	flag;

	if (pthread_mutex_lock(&philo->data->display))
		return (1);
	pthread_mutex_lock(&philo->data->check);
	flag = philo->data->simulation_end;
	if (flag)
		return (pthread_mutex_unlock(&philo->data->display), \
			pthread_mutex_unlock(&philo->data->check), 1);
	printf("| %6ld ms | %8d | %-16s |\n", \
		ph_get_time() - philo->data->start_time, philo->id, status);
	return (pthread_mutex_unlock(&philo->data->display), \
		pthread_mutex_unlock(&philo->data->check), 0);
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
