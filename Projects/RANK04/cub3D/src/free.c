/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:41:44 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/20 19:33:19 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	free_mlx_imgs(t_cub *cub)
{
	mlx_destroy_image(cub->mlx.mlx, cub->directions.east.img);
	mlx_destroy_image(cub->mlx.mlx, cub->directions.north.img);
	mlx_destroy_image(cub->mlx.mlx, cub->directions.south.img);
	mlx_destroy_image(cub->mlx.mlx, cub->directions.west.img);
}

void	free_mlx(t_mlx mlx)
{
	mlx_destroy_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
}

void	free_img(t_img img)
{
	if (img.path)
		free(img.path);
}

void	free_map(t_map map)
{
	if (map.map)
		multiple_free("%b", map.map);
}

void	free_file(t_file file)
{
	if (file.filename)
		free(file.filename);
	if (file.content)
		multiple_free("%b", file.content);
}
