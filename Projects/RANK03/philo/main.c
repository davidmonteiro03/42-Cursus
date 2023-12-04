/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/04 09:38:16 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (printf("Invalid number of arguments\n"), 1);
	if (ph_check_input(-1, argv + 1))
		return (printf("Invalid arguments\n"), 1);
	philo = NULL;
	if (ph_init_all(&philo, argv, -1))
		return (printf("Error on initialization of structure\n"), 1);
	if (ph_execute(philo, -1))
		return (printf("Error on execution\n"), 1);
	return (ph_clear_all(philo, -1));
}
