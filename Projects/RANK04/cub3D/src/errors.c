/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:23:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/11 21:43:17 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	cub_error(char *error)
{
	printf("Error\n");
	printf("%s\n", error);
	exit(1);
}

void	cub_error_file(t_cub *cub, char *error, bool perror_flag)
{
	printf("Error\n");
	if (perror_flag)
		perror(error);
	else
		printf("%s\n", error);
	free_file(cub->config);
	free(cub);
	exit(1);
}
