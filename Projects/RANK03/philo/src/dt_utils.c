/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:14:58 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/27 12:52:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	dt_iin(t_dt **dt, char **v)
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
	return (0);
}
