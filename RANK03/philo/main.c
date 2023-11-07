/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 12:04:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*philo_create(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("PHILO %d created!\n", philo->pos);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philo;
	int			np;
	int			i;

	if (ac != 5)
		return (0);
	np = philo_atol(av[1]);
	philo_info(&info, av);
	info_range(info, np);
	philo = (t_philo *)malloc(sizeof(t_philo) * np);
	i = -1;
	while (++i < np)
	{
		philo[i].info = info;
		philo[i].pos = i + 1;
		pthread_create(&philo[i].id, NULL, philo_create, &philo[i]);
	}
	i = -1;
	while (++i < np)
		pthread_join(philo[i].id, NULL);
	free(philo);
	return (0);
}
