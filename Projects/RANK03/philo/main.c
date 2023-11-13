/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 09:32:48 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int ac, char **av)
{
	t_inf	inf;

	if (ac != 5 && ac != 6)
		return (error("Error usage"));
	if (!check_args(ac, av))
		return (error("Error in arguments"));
	if (init_inf(&inf, ac, av) != 0)
		return (error("Error building the structure"));
	clean_all(&inf, 4);
	return (0);
}
