/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:47:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/08 14:52:43 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	usage_std(void)
{
	printf("|%-57s", "  arg1: number_of_philosophers");
	printf("❌ |\n");
	printf("|%-57s", "  arg2: time_to_die (in milliseconds)");
	printf("❌ |\n");
	printf("|%-57s", "  arg3: time_to_eat (in milliseconds)");
	printf("❌ |\n");
	printf("|%-57s", "  arg4: time_to_sleep (in milliseconds)");
	printf("❌ |\n");
	printf("|%-60s|\n", "  arg5: number_of_times_each_philosopher_must_eat \
[opt.]");
}

void	usage_1(char **av)
{
	printf("|%s", "  arg1: ");
	if (ph_atol(av[1]) > 2147483647 || ph_atol(av[1]) <= 0)
		printf("%-40s %11s |\n", av[1], "❌");
	else
		printf("%-11ld %40s |\n", ph_atol(av[1]), "✅");
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
	if (ph_atol(av[1]) > 2147483647 || ph_atol(av[1]) <= 0)
		printf("%-40s %11s |\n", av[1], "❌");
	else
		printf("%-11ld %40s |\n", ph_atol(av[1]), "✅");
	printf("|%s", "  arg2: ");
	if (ph_atol(av[2]) > 2147483647 || ph_atol(av[2]) <= 0)
		printf("%-40s %11s |\n", av[2], "❌");
	else
		printf("%-11ld %40s |\n", ph_atol(av[2]), "✅");
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
	if (ph_atol(av[1]) > 2147483647 || ph_atol(av[1]) <= 0)
		printf("%-40s %11s |\n", av[1], "❌");
	else
		printf("%-11ld %40s |\n", ph_atol(av[1]), "✅");
	printf("|%s", "  arg2: ");
	if (ph_atol(av[2]) > 2147483647 || ph_atol(av[2]) <= 0)
		printf("%-40s %11s |\n", av[2], "❌");
	else
		printf("%-11ld %40s |\n", ph_atol(av[2]), "✅");
	printf("|%s", "  arg3: ");
	if (ph_atol(av[3]) > 2147483647 || ph_atol(av[3]) <= 0)
		printf("%-40s %11s |\n", av[3], "❌");
	else
		printf("%-11ld %40s |\n", ph_atol(av[3]), "✅");
	printf("|%-57s", "  arg4: time_to_sleep (in milliseconds)");
	printf("❌ |\n");
	printf("|%-60s|\n", "  arg5: number_of_times_each_philosopher_must_eat \
[opt.]");
}
