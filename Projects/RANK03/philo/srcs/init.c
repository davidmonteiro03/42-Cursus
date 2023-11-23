/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:31:10 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 10:44:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_inf	*ph_alloc(void)
{
	t_inf	*inf;

	inf = (t_inf *)malloc(sizeof(t_inf));
	if (!inf)
		return (NULL);
	return (inf);
}

void	ph_init_mutex(t_inf **inf)
{
	int	i;

	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_mutex_init(&(*inf)->forks[i], NULL);
	pthread_mutex_init((*inf)->print, NULL);
}

int	ph_init_ph(t_inf **inf)
{
	int	i;

	i = -1;
	while (++i < (*inf)->num_ph)
	{
		(*inf)->ph[i].ph_num = i + 1;
		(*inf)->ph[i].last_meal = -1;
		(*inf)->ph[i].inf = *inf;
	}
	return (0);
}

int	ph_init_inf(t_inf **inf, char **av)
{
	(*inf)->num_ph = ph_atol(av[1]);
	(*inf)->time_die = ph_atol(av[2]);
	(*inf)->time_eat = ph_atol(av[3]);
	(*inf)->time_sleep = ph_atol(av[4]);
	(*inf)->num_eat = -1;
	if (av[5])
		(*inf)->num_eat = ph_atol(av[5]);
	(*inf)->ph = (t_ph *)malloc(sizeof(t_ph) * (*inf)->num_ph);
	(*inf)->th = (t_th *)malloc(sizeof(t_th) * (*inf)->num_ph);
	(*inf)->forks = (t_mutex *)malloc(sizeof(t_mutex) * (*inf)->num_ph);
	(*inf)->print = (t_mutex *)malloc(sizeof(t_mutex));
	if (!(*inf)->ph || !(*inf)->th || !(*inf)->forks)
		return (ph_exit(inf, 1));
	ph_init_mutex(inf);
	ph_init_ph(inf);
	return (0);
}
