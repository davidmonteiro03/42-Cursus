/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:44:34 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 16:41:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_ph	*ph_new(t_dt *dt, int id)
{
	t_ph	*ph;

	ph = malloc(sizeof(t_ph));
	if (!ph)
		return (NULL);
	ph->lf = &dt->fk[id - 1];
	ph->rf = &dt->fk[(id + 1) % dt->np];
	ph->dt = dt;
	ph->id = id;
	ph->nt = NULL;
	return (ph);
}

void	ph_add(t_ph **ph, t_ph *nd)
{
	t_ph	*tp;

	if (!*ph)
	{
		*ph = nd;
		return ;
	}
	tp = *ph;
	while (tp->nt)
		tp = tp->nt;
	tp->nt = nd;
}

void	ph_clr(t_dt **dt, int i)
{
	t_ph	*tp;

	tp = (*dt)->ph;
	while (tp)
	{
		pthread_join(tp->th, NULL);
		tp = tp->nt;
	}
	while ((*dt)->ph)
	{
		tp = (*dt)->ph;
		(*dt)->ph = (*dt)->ph->nt;
		free(tp);
	}
	while (++i < (*dt)->np)
		pthread_mutex_destroy(&(*dt)->fk[i]);
	free((*dt)->fk);
	free(*dt);
}

int	ph_fin(t_dt **dt, int i)
{
	while (++i < (*dt)->np)
		pthread_mutex_init(&(*dt)->fk[i], NULL);
	return (0);
}

int	ph_pin(t_dt **dt, int i)
{
	t_ph	*nd;

	(*dt)->ph = NULL;
	while (++i < (*dt)->np)
	{
		nd = ph_new(*dt, i + 1);
		if (!nd)
		{
			ph_clr(dt, -1);
			return (1);
		}
		ph_add(&(*dt)->ph, nd);
	}
	ph_fin(dt, -1);
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
