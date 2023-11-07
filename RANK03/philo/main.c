/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 11:55:57 by dcaetano         ###   ########.fr       */
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
	int			i;

	if (ac != 5)
		return (0);
	philo_info(&info, av);
	info_range(info);
	philo = (t_philo *)malloc(sizeof(t_philo) * info.np);
	i = -1;
	while (++i < info.np)
	{
		philo[i].pos = i + 1;
		pthread_create(&philo[i].id, NULL, philo_create, &philo[i]);
	}
	i = -1;
	while (++i < info.np)
		pthread_join(philo[i].id, NULL);
	free(philo);
	return (0);
}
