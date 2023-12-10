/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:23:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 19:12:22 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	cub_error(char *error)
{
	write(2, "Error\n", 6);
	while (*error)
		write(2, error++, 1);
	write(2, "\n", 1);
	exit(1);
}

void	cub_error_file(t_cub *cub, char *error, bool perror_flag)
{
	write(2, "Error\n", 6);
	if (perror_flag)
		perror(error);
	else
		ft_printf("%s\n", error);
	free_file(cub->config);
	free(cub);
	exit(1);
}
