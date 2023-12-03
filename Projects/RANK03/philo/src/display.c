/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:17:56 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/03 15:12:03 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ph_status(t_philo *philo, char *status)
{
	printf("%5lld ms | %3d %-20s\n", \
		ph_get_time() - philo->data->start, \
		philo->id, \
		status \
	);
}
