/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:52:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 08:59:51 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_clear_all(t_philo *philo)
{
	if (!philo)
		return (1);
	if (philo->data->print)
	{
		pthread_mutex_destroy(philo->data->print);
		free(philo->data->print);
	}
	if (philo->data)
		free(philo->data);
	return (free(philo), 0);
}
