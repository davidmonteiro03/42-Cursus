/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:34 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/30 19:49:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_philo	*ph_create_node(t_data *data, int id)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->left_fork = &data->forks[id - 1];
	philo->right_fork = &data->forks[(id + 1) % data->num_philos];
	philo->data = data;
	philo->id = id;
	philo->next = NULL;
	return (philo);
}

void	ph_add_node(t_philo **philo, t_philo *node)
{
	t_philo	*temp;

	if (!*philo)
	{
		*philo = node;
		return ;
	}
	temp = *philo;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	ph_clear(t_data **data, int i)
{
	t_philo	*temp;

	temp = (*data)->philos;
	while (temp)
	{
		pthread_join(temp->thread, NULL);
		temp = temp->next;
	}
	while ((*data)->philos)
	{
		temp = (*data)->philos;
		(*data)->philos = (*data)->philos->next;
		free(temp);
	}
	while (++i < (*data)->num_philos)
		pthread_mutex_destroy(&(*data)->forks[i]);
	free((*data)->forks);
	free(*data);
}

int	ph_forks_init(t_data **data, int i)
{
	while (++i < (*data)->num_philos)
		pthread_mutex_init(&(*data)->forks[i], NULL);
	return (0);
}

int	ph_philo_init(t_data **data, int i)
{
	t_philo	*node;

	(*data)->philos = NULL;
	while (++i < (*data)->num_philos)
	{
		node = ph_create_node(*data, i + 1);
		if (!node)
		{
			ph_clear(data, -1);
			return (1);
		}
		ph_add_node(&(*data)->philos, node);
	}
	ph_forks_init(data, -1);
	return (0);
}

/* void	ph_dsp(t_ph *ph)
{
	t_ph	*tmp;

	tmp = ph;
	while (tmp)
	{
		printf("philo %d\n", tmp->id);
		tmp = tmp->nt;
	}
} */
