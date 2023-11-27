/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:14:58 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 16:41:35 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_din(t_dt **dt, char **v)
{
	*dt = malloc(sizeof(t_dt));
	if (!*dt)
		return (1);
	(*dt)->np = ph_num(v[0]);
	(*dt)->td = ph_num(v[1]);
	(*dt)->te = ph_num(v[2]);
	(*dt)->ts = ph_num(v[3]);
	(*dt)->ne = -1;
	if (v[4])
		(*dt)->ne = ph_num(v[4]);
	(*dt)->fk = malloc(sizeof(t_mt) * (*dt)->np);
	return (0);
}
