/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 15:46:32 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_philo	**philo;
	t_info	info;

	if (ac != 5 && ac != 6)
		return (EXIT_FAILURE);
	philo_info(&info, av);
	philo = (t_philo **)malloc(sizeof(t_philo *) * philo_atoi(av[1]));
	create_philo(philo, philo_atoi(av[1]));
	join_philo(philo, philo_atoi(av[1]));
	free_philo(philo, philo_atoi(av[1]));
	return (EXIT_SUCCESS);
}
