/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:10:35 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 09:32:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	clean_mutex(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->num_ph)
		pthread_mutex_destroy(&inf->forks[i]);
}

void	clean_all(t_inf *inf, int code)
{
	if (code == 0)
		return ;
	else if (code == 1)
		return (free(inf->forks));
	else if (code == 2)
		return (clean_mutex(inf), free(inf->forks));
	else if (code == 3)
		return (clean_mutex(inf), free(inf->ph), free(inf->forks));
	else if (code == 4)
		return (clean_mutex(inf), free(inf->th), free(inf->ph), \
			free(inf->forks));
}
