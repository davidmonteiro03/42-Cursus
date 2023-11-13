/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:53:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/11 17:56:41 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error(char *error)
{
	if (!error)
		printf("Error\n");
	else
		printf("%s\n", error);
	return (EXIT_FAILURE);
}
