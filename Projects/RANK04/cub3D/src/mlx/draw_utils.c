/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:12:50 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/04 00:46:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_last_column(t_cub *cub, int x, int y)
{
	auto int tmp_y = y * MMAP_SZ - 1;
	while (++tmp_y < (y + 1) * MMAP_SZ + STROKE - 1)
	{
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			x * MMAP_SZ, tmp_y, BORDER_COLOR);
		auto int tmp_i = -1;
		while (++tmp_i < STROKE)
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				x * MMAP_SZ + tmp_i, tmp_y, BORDER_COLOR);
	}
}

void	cub_draw_last_line(t_cub *cub, int x, int y)
{
	auto int tmp_x = -1;
	while (++tmp_x < x * MMAP_SZ + STROKE)
	{
		mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
			tmp_x, y * MMAP_SZ, BORDER_COLOR);
		auto int tmp_i = -1;
		while (++tmp_i < STROKE)
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				tmp_x, y * MMAP_SZ + tmp_i, BORDER_COLOR);
	}
}

void	cub_draw_shape(t_mlx mlx, int x, int y, t_color color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MMAP_SZ)
	{
		j = -1;
		while (++j < MMAP_SZ)
			mlx_pixel_put(mlx.mlx, mlx.win, \
				x * MMAP_SZ + j, y * MMAP_SZ + i, color.hex);
	}
}

void	cub_check_shape(t_cub *cub, int x, int y, char c)
{
	if (c == '1')
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, WALL_COLOR});
	else if (c == '0' || c == ' ' || c == cub->player.c)
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, FLOOR_COLOR});
	else if (c == '-')
		cub_draw_shape(cub->mlx, x, y, (t_color){0, 0, 0, EMPTY_COLOR});
}

void	cub_update_angle(t_cub *cub, int angle)
{
	cub->player.angle += angle;
	usleep(10000);
}
