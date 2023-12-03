/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:43 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/03 17:45:29 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (1);
	if (ph_check_input(-1, argv + 1))
		return (1);
	data = NULL;
	if (ph_data_init(&data, argv + 1))
		return (1);
	if (ph_philo_init(&data, -1))
		return (1);
	return (ph_execute(data), ph_clear_all(&data, -1), 0);
}
