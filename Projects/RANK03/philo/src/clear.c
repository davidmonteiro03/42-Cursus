/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 08:45:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_clear_data(t_data *data)
{
	if (!data)
		return ;
	if (data->display)
	{
		pthread_mutex_destroy(data->display);
		free(data->display);
	}
	free(data);
}

int	ph_clear_all(t_philo *philo, int i)
{
	if (!philo)
		return (1);
	while (++i < philo->data->num_philos)
	{
		pthread_mutex_destroy(philo[i].right_fork);
		free(philo[i].right_fork);
	}
	return (ph_clear_data(philo->data), free(philo), 0);
}
