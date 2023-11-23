/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:49:41 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 10:45:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ph_exit(t_inf **inf, int status)
{
	int	i;

	if (!*inf)
		return (1);
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_join((*inf)->th[i], NULL);
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_mutex_destroy(&(*inf)->forks[i]);
	pthread_mutex_destroy((*inf)->print);
	if ((*inf)->print)
		free((*inf)->print);
	if ((*inf)->ph)
		free((*inf)->ph);
	if ((*inf)->th)
		free((*inf)->th);
	if ((*inf)->forks)
		free((*inf)->forks);
	free(*inf);
	return (status);
}
