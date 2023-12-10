/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 18:23:31 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 14:26:43 by dcaetano         ###   ########.fr       */
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

void	cub_error_parsing(t_cub *cub, char *error)
{
	write(2, "Error\n", 6);
	while (*error)
		write(2, error++, 1);
	write(2, "\n", 1);
	free(cub);
	exit(1);
}

void	cub_clear_error1(t_cub *cub, char *error)
{
	multiple_free("%b", cub->config.data.file_content);
	cub_error_parsing(cub, error);
}

void	cub_clear_error2(t_cub *cub, char *error)
{
	multiple_free("%b%c", cub->config.data.file_content, \
		cub->config.data.data);
	cub_error_parsing(cub, error);
}
