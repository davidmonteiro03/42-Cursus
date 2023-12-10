/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:44:01 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/10 15:02:14 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	cub_destroy_mlx(t_mlx mlx)
{
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}

int	cub_exit(t_cub *cub)
{
	cub_destroy_mlx(cub->mlx);
	multiple_free("%c%b%a", cub->config.data.data, \
		cub->config.data.file_content, cub);
	exit(0);
}
