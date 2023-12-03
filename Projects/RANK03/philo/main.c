/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/03 21:45:33 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (1);
	if (ph_check_input(-1, argv + 1))
		return (1);
	philo = NULL;
	if (ph_init(&philo, argv, -1))
		return (1);
	if (ph_execute(philo, -1))
		return (1);
	return (0);
}
