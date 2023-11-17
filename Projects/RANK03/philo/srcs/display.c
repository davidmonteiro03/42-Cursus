/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 08:56:07 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/17 09:35:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	start(void)
{
	printf("+-------------+-------+-------------------------+\n");
	printf("| %-11s | %-5s | %-23s |\n", \
		"TIMESTAMP", \
		"PHILO", \
		"STATUS" \
	);
	printf("+-------------+-------+-------------------------+\n");
}

void	end(void)
{
	printf("+-------------+-------+-------------------------+\n");
}