/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:06:59 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/14 17:19:01 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	clean_inf(t_inf **inf)
{
	int	i;

	if (!inf || !*inf)
		return (1);
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_join((*inf)->th[i], NULL);
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_mutex_destroy(&(*inf)->f[i]);
	free((*inf)->ph);
	free((*inf)->f);
	free((*inf)->th);
	free(*inf);
	return (0);
}
