/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:34 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 13:16:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_ph	*ph_new(t_dt *dt, int id)
{
	t_ph	*ph;

	ph = malloc(sizeof(t_ph));
	if (!ph)
		return (NULL);
	ph->dt = dt;
	ph->id = id;
	ph->nt = NULL;
	return (ph);
}

void	ph_add(t_ph **ph, t_ph *new)
{
	t_ph	*tmp;

	if (!*ph)
	{
		*ph = new;
		return ;
	}
	tmp = *ph;
	while (tmp->nt)
		tmp = tmp->nt;
	tmp->nt = new;
}

void	ph_clr(t_ph **ph)
{
	t_ph	*tmp;
	t_ph	*sve;

	sve = *ph;
	while (sve)
	{
		pthread_join(sve->th, NULL);
		sve = sve->nt;
	}
	while (*ph)
	{
		tmp = *ph;
		*ph = (*ph)->nt;
		free(tmp);
	}
}

int	ph_iin(t_ph **ph, t_dt *dt, int i)
{
	t_ph	*nd;

	while (++i < dt->np)
	{
		nd = ph_new(dt, i + 1);
		if (!nd)
		{
			ph_clr(ph);
			return (1);
		}
		ph_add(ph, nd);
	}
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
