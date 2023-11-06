/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/06 19:41:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	philo(t_philos *philos, char **av)
{
	philos->np = philo_atou(av[1]);
	philos->ttd = philo_atou(av[2]);
	philos->tte = philo_atou(av[3]);
	philos->tts = philo_atou(av[4]);
	philos->notepme = philo_atou(av[5]);
}

int	main(int ac, char **av)
{
	t_philos	philos;

	if (ac != 5 && ac != 6)
		return (0);
	philo(&philos, av);
	return (0);
}
