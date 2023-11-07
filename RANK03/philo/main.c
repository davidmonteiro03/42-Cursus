/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/07 19:40:20 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*routine(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	return (NULL);
}

void	philo_1(t_info *info)
{
	display_status(&info->ph[0], "is thinking");
	philo_waitms(info->ttd);
	display_status(&info->ph[0], "died");
}

void	confusion(t_info *info)
{
	int	i;

	info->st = get_time();
	if (info->np == 1)
		return (philo_1(info));
	i = -1;
	while (++i < info->np)
		pthread_create(&info->th[i], NULL, &routine, &info->ph[i]);
}

int	main(int ac, char **av)
{
	t_info	info;

	check_args(ac, av);
	init_info(&info, ac, av);
	init_philos(&info);
	init_forks(&info);
	confusion(&info);
	return (0);
}
