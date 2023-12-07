/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:40:57 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/07 17:06:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_data	*ph_init_data(char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_philos = ph_atol(argv[1]);
	data->time_to_die = ph_atol(argv[2]);
	data->time_to_eat = ph_atol(argv[3]);
	data->time_to_sleep = ph_atol(argv[4]);
	data->num_meals_per_philo = -1;
	data->simulation_end = false;
	if (argv[5])
		data->num_meals_per_philo = ph_atol(argv[5]);
	data->num_finish_meals = 0;
	pthread_mutex_init(&data->check, NULL);
	return (pthread_mutex_init(&data->display, NULL), data);
}

void	ph_init_philos(t_philo **philo, t_data *data, int i)
{
	while (++i < data->num_philos)
	{
		(*philo)[i].id = i + 1;
		(*philo)[i].meals_count = 0;
		(*philo)[i].last_meal = -1;
		(*philo)[i].data = data;
		(*philo)[i].done = false;
		(*philo)[i].right_fork = (t_mutex *)malloc(sizeof(t_mutex));
		pthread_mutex_init((*philo)[i].right_fork, NULL);
	}
}

int	ph_init_all(t_philo **philo, char **argv, int i)
{
	t_data	*data;

	data = ph_init_data(argv);
	if (!data)
		return (1);
	*philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philos);
	if (!*philo)
		return (ph_clear_data(data), 1);
	ph_init_philos(philo, data, -1);
	while (++i < data->num_philos)
	{
		if (i == 0)
			(*philo)[i].left_fork = (*philo)[data->num_philos - 1].right_fork;
		else
			(*philo)[i].left_fork = (*philo)[i - 1].right_fork;
		pthread_mutex_init((*philo)[i].left_fork, NULL);
	}
	return (0);
}
