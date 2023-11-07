/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 13:39:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	int			np;

	if (ac != 5)
		return (0);
	np = philo_atol(av[1]);
	philo_info(&info, av);
	info_range(info, np);
	philo = (t_philo *)malloc(sizeof(t_philo) * np);
	create_philos(philo, info, np);
	join_philos(philo, np);
	free(philo);
	return (0);
}
