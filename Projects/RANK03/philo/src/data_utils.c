/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:14:58 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 20:57:49 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_data_init(t_data **data, char **av)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (1);
	(*data)->num_philos = ph_atol(av[0]);
	(*data)->time_to_die = ph_atol(av[1]);
	(*data)->time_to_eat = ph_atol(av[2]);
	(*data)->time_to_sleep = ph_atol(av[3]);
	(*data)->num_of_meals_for_ph = -1;
	if (av[4])
		(*data)->num_of_meals_for_ph = ph_atol(av[4]);
	(*data)->forks = malloc(sizeof(t_mutex) * (*data)->num_philos);
	return (0);
}
