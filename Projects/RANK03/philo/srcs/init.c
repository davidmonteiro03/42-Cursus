/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:56:28 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/14 14:05:24 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_inf(t_inf **inf, int ac, char **av)
{
	*inf = (t_inf *)malloc(sizeof(t_inf));
	if (!inf)
		return (1);
	(*inf)->num_ph = ph_atoi(av[1]);
	(*inf)->time_die = ph_atoi(av[2]);
	(*inf)->time_eat = ph_atoi(av[3]);
	(*inf)->time_sleep = ph_atoi(av[4]);
	(*inf)->num_meals_ph = -1;
	if (ac == 6 && av[5] && *av[5])
		(*inf)->num_meals_ph = ph_atoi(av[5]);
	return (0);
}
