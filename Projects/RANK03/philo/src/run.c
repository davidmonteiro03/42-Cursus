/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:04 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 16:23:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ph_th(void *ag)
{
	t_ph	*ph;

	ph = (t_ph *)ag;
	return (NULL);
}

void	ph_run(t_dt *dt)
{
	t_ph	*tp;

	tp = dt->ph;
	while (tp)
	{
		pthread_create(&tp->th, NULL, &ph_th, tp);
		tp = tp->nt;
	}
}