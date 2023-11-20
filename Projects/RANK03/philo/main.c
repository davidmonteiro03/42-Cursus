/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/20 18:56:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	confusion(t_inf **inf)
{
	if ((*inf)->num_ph == 1)
		return (philo_1(inf), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_inf	*inf;
	int		status;
	bool	type;

	if (ac != 5 && ac != 6)
		return (error("Error usage"));
	if (!check_args(ac, av))
		return (error("Error in arguments"));
	inf = NULL;
	if (init_inf(&inf, ac, av) != 0)
		return (1);
	start();
	type = false;
	if (confusion(&inf))
		type = false;
	status = clean_inf(&inf, type);
	end();
	return (status);
}
