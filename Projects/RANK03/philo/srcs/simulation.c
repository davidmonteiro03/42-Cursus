/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:08:17 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/23 10:52:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ph_routine(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	ph_status(ph, THINK);
	ph_eating(ph);
	return (NULL);
}

void	ph_start(t_inf **inf)
{
	int	i;

	(*inf)->start_time = get_time();
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_create(&(*inf)->th[i], NULL, &ph_routine, &(*inf)->ph[i]);
}
