/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/14 18:49:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	*routine(void *philo)
{
	static bool	end;
	t_ph		*ph;

	ph = (t_ph *)philo;
	while (!end)
	{
		pthread_mutex_lock(ph->inf->action_lock);
		if (ph->ph_id == 2)
		{
			end = true;
			printf("AAAA => kkasksd\n");
			pthread_mutex_unlock(ph->inf->action_lock);
			pthread_exit(NULL);
		}
		else if (!end)
			printf("AAAA => %d\n", ph->ph_id);
		pthread_mutex_unlock(ph->inf->action_lock);
	}
	return (NULL);
}

int	confusion(t_inf **inf)
{
	int	i;

	if (!*inf)
		return (1);
	i = -1;
	while (++i < (*inf)->num_ph)
		pthread_create(&(*inf)->th[i], NULL, &routine, &(*inf)->ph[i]);
	return (0);
}

int	main(int ac, char **av)
{
	t_inf	*inf;

	if (ac != 5 && ac != 6)
		return (error("Error usage"));
	if (!check_args(ac, av))
		return (error("Error in arguments"));
	inf = NULL;
	if (init_inf(&inf, ac, av) != 0)
		return (1);
	if (confusion(&inf) != 0)
		return (clean_inf(&inf));
	return (clean_inf(&inf));
}
