/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:40:14 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 10:59:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	error_message(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

void	check_num_args(int ac, char **av)
{
	if (ac == 2)
		usage_1(av);
	if (ac == 3)
		usage_2(av);
	if (ac == 4)
		usage_3(av);
}

void	error_usage(int ac, char **av)
{
	printf("\n");
	printf("+------------------------------------------------------------+\n");
	printf("|%-60s|\n", "");
	printf("|%-60s|\n", "  USAGE");
	printf("|%-60s|\n", "");
	check_num_args(ac, av);
	printf("|%-60s|\n", "");
	printf("+------------------------------------------------------------+\n");
	printf("\n");
	exit(EXIT_FAILURE);
}
