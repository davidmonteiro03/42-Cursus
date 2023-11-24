/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:21:09 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/24 12:00:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_ph	*ph_iph(t_in *in)
{
	t_ph	*ph;
	int		i;

	if (!in)
		return (NULL);
	ph = malloc(sizeof(t_ph) * in->dt->np);
	if (!ph)
		return (NULL);
	i = -1;
	while (++i < in->dt->np)
	{
		ph[i].id = i + 1;
		ph[i].in = in;
	}
	return (ph);
}

t_dt	*ph_idt(char **v)
{
	t_dt	*dt;

	dt = malloc(sizeof(t_dt));
	if (!dt)
		return (NULL);
	dt->np = ph_num(v[1]);
	dt->td = ph_num(v[2]);
	dt->te = ph_num(v[3]);
	dt->ts = ph_num(v[4]);
	dt->ne = -1;
	if (v[5])
		dt->ne = ph_num(v[5]);
	return (dt);
}

t_in	*ph_iin(char **v)
{
	t_in	*in;

	in = malloc(sizeof(t_in));
	if (!in)
		return (NULL);
	in->dt = ph_idt(v);
	if (!in->dt)
		return (free(in), NULL);
	in->ph = ph_iph(in);
	if (!in->ph)
		return (free(in->dt), free(in), NULL);
	return (in);
}
