/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:47:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 11:16:06 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	usage_1(char **av)
{
	printf("|%s", "  arg1: ");
	printf("%-3d %48s |\n", ph_atoi(av[1]), "✅");
	printf("|%-57s", "  arg2: time_to_die (in milliseconds)");
	printf("❌ |\n");
	printf("|%-57s", "  arg3: time_to_eat (in milliseconds)");
	printf("❌ |\n");
	printf("|%-57s", "  arg4: time_to_sleep (in milliseconds)");
	printf("❌ |\n");
	printf("|%-60s|\n", "  arg5: number_of_times_each_philosopher_must_eat \
[opt.]");
}

void	usage_2(char **av)
{
	printf("|%s", "  arg1: ");
	printf("%-3d %48s |\n", ph_atoi(av[1]), "✅");
	printf("|%s", "  arg2: ");
	printf("%-3d %48s |\n", ph_atoi(av[2]), "✅");
	printf("|%-57s", "  arg3: time_to_eat (in milliseconds)");
	printf("❌ |\n");
	printf("|%-57s", "  arg4: time_to_sleep (in milliseconds)");
	printf("❌ |\n");
	printf("|%-60s|\n", "  arg5: number_of_times_each_philosopher_must_eat \
[opt.]");
}

void	usage_3(char **av)
{
	printf("|%s", "  arg1: ");
	printf("%-3d %48s |\n", ph_atoi(av[1]), "✅");
	printf("|%s", "  arg2: ");
	printf("%-3d %48s |\n", ph_atoi(av[2]), "✅");
	printf("|%s", "  arg3: ");
	printf("%-3d %48s |\n", ph_atoi(av[3]), "✅");
	printf("|%-57s", "  arg4: time_to_sleep (in milliseconds)");
	printf("❌ |\n");
	printf("|%-60s|\n", "  arg5: number_of_times_each_philosopher_must_eat \
[opt.]");
}
