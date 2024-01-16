/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:36:34 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/16 13:08:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_mlx(t_mlx mlx)
{
	if (mlx.win)
		mlx_destroy_window(mlx.mlx, mlx.win);
	if (mlx.mlx)
		mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}

int	cub_exit(t_cub *cub)
{
	free_img(cub->mlx.mlx, cub->directions.east);
	free_img(cub->mlx.mlx, cub->directions.west);
	free_img(cub->mlx.mlx, cub->directions.north);
	free_img(cub->mlx.mlx, cub->directions.south);
	free_mlx(cub->mlx);
	free_file(cub->config);
	free_map(cub->map);
	free(cub);
	exit(0);
}
