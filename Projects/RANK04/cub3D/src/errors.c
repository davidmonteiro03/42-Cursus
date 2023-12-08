/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:23:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/08 19:07:10 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	cub_error(char *error, bool perror_flag)
{
	char	*tmp;

	tmp = error;
	write(2, "Error\n", 6);
	if (perror_flag)
		perror(error);
	else
	{
		while (*error)
			write(2, error++, 1);
		write(2, "\n", 1);
	}
	free(tmp);
	exit(1);
}
