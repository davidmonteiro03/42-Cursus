/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:07:27 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 08:12:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_inf(t_inf *inf, int ac, char **av)
{
	inf->num_ph = ph_atoi(av[1]);
	inf->time_die = ph_atoi(av[2]);
	inf->time_eat = ph_atoi(av[3]);
	inf->time_sleep = ph_atoi(av[4]);
	inf->num_time_meals_ph = -1;
	if (ac == 6)
		inf->num_time_meals_ph = ph_atoi(av[5]);
	inf->ph = (t_ph *)malloc(sizeof(t_ph) * inf->num_ph);
	if (!inf->ph)
		return (1);
	return (0);
}
