/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:06:59 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/14 18:45:46 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	clean_inf(t_inf **inf)
{
	int	i;

	if (!*inf)
		return (1);
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_join((*inf)->th[i], NULL);
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_mutex_destroy(&(*inf)->f[i]);
	pthread_mutex_destroy((*inf)->action_lock);
	if ((*inf)->ph)
		free((*inf)->ph);
	if ((*inf)->f)
		free((*inf)->f);
	if ((*inf)->th)
		free((*inf)->th);
	if ((*inf)->action_lock)
		free((*inf)->action_lock);
	free(*inf);
	return (0);
}
