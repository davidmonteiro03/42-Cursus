/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:40:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 10:36:25 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_message(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	error_usage(void)
{
	printf("\n");
	printf("+------------------------------------------------------------+\n");
	printf("|%-60s|\n", "");
	printf("|%-60s|\n", "  USAGE");
	printf("|%-60s|\n", "");
	printf("|%-60s|\n", "  arg1: number_of_philosophers");
	printf("|%-60s|\n", "  arg2: time_to_die (in milliseconds)");
	printf("|%-60s|\n", "  arg3: time_to_eat (in milliseconds)");
	printf("|%-60s|\n", "  arg4: time_to_sleep (in milliseconds)");
	printf("|%-60s|\n", "  arg5: number_of_times_each_philosopher_must_eat \
[opt.]");
	printf("|%-60s|\n", "");
	printf("+------------------------------------------------------------+\n");
	printf("\n");
	exit(EXIT_FAILURE);
}
