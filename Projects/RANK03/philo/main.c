/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 13:18:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

void	*ph_th(void *arg)
{
	t_ph	*ph;

	ph = (t_ph *)arg;
	printf("philo %d\n", ph->id);
	return (NULL);
}

void	ph_run(t_ph *ph)
{
	t_ph	*tmp;

	tmp = ph;
	while (tmp)
	{
		pthread_create(&tmp->th, NULL, ph_th, tmp);
		tmp = tmp->nt;
	}
}

int	main(int c, char **v)
{
	t_ph	*ph;
	t_dt	*dt;

	if (c != 5 && c != 6)
		return (1);
	if (ph_chk(-1, v + 1))
		return (1);
	ph = NULL;
	dt = NULL;
	if (dt_iin(&dt, v + 1) != 0)
		return (1);
	if (ph_iin(&ph, dt, -1) != 0)
		return (1);
	ph_run(ph);
	ph_clr(&ph);
	free(dt);
	return (0);
}
