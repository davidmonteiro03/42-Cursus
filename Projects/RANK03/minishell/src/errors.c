/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:20:32 by dcaetano          #+#    #+#             */
/*   Updated: 2023/11/13 12:32:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	usage(void)
{
	printf("Usage: ./minishell\n");
	exit(EXIT_FAILURE);
}

void	error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}
