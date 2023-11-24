/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:27:38 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/24 11:51:18 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ph_clr(t_in *in, int st)
{
	if (!in)
		return (1);
	if (in->dt)
		free(in->dt);
	if (in->ph)
		free(in->ph);
	return (free(in), st);
}
