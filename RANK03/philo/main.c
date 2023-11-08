/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 11:00:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo_1(t_inf *inf)
{
	status(&inf->ph[0], "is thinking");
	usleep(inf->ttd);
	status(&inf->ph[0], "died");
}

void	confusion(t_inf *inf)
{
	inf->st = get_time();
	if (inf->np == 1)
		return (philo_1(inf));
}

void	peace(t_inf *inf)
{
	if (inf->ph)
		free(inf->ph);
}

int	main(int ac, char **av)
{
	t_inf	inf;

	if (ac != 5 && ac != 6)
		error_usage(ac, av);
	check_args(ac, av);
	init_inf(&inf, ac, av);
	init_philos(&inf);
	confusion(&inf);
	peace(&inf);
	return (0);
}
