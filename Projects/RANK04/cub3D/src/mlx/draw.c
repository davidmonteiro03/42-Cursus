/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:32:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 07:42:58 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_shape(t_mlx mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MMAP_SZ)
	{
		j = -1;
		while (++j < MMAP_SZ)
			mlx_pixel_put(mlx.mlx, mlx.win, \
				x * MMAP_SZ + j, y * MMAP_SZ + i, color);
	}
}

void	cub_draw_map(t_cub *cub, char **map, int y)
{
	int	x;

	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				cub_draw_shape(cub->mlx, x, y, cub->ceiling.hex);
			else if (map[y][x] == '0' || map[y][x] == ' ' ||
				ft_strchr("NSEW", map[y][x]))
				cub_draw_shape(cub->mlx, x, y, cub->floor.hex);
			if (map[y][x] == '-')
				cub_draw_shape(cub->mlx, x, y, 0x999999);
		}
	}
	if (cub->player.angle == 360)
		cub->player.angle = 0;
	if (cub->player.angle < 0)
		cub->player.angle += 360;
}

void	cub_draw_view(t_cub *cub)
{
	auto double player_x = cub->player.x;
	auto double player_y = cub->player.y;
	auto double view_angle = 90;
	auto int ray_count = 1000;
	auto int i = -1;
	while (++i < ray_count)
	{
		auto double ray_angle = cub->player.angle - (view_angle / 2) + \
			(view_angle * i / ray_count);
		auto double ray_x = cos(ray_angle * M_PI / 180.0);
		auto double ray_y = sin(ray_angle * M_PI / 180.0);
		auto double x = player_x;
		auto double y = player_y;
		while (x >= 0 && y >= 0 && x < cub->map.width * MMAP_SZ && \
			y < cub->map.height * MMAP_SZ && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '1' && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '-')
		{
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				(int)x, (int)y, 0x666666);
			x += ray_x;
			y += ray_y;
		}
	}
}

void	cub_mlx(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	cub->directions.east.img = \
		cub_new_image(cub->mlx.mlx, &cub->directions.east);
	cub->directions.south.img = \
		cub_new_image(cub->mlx.mlx, &cub->directions.south);
	cub->directions.north.img = \
		cub_new_image(cub->mlx.mlx, &cub->directions.north);
	cub->directions.west.img = \
		cub_new_image(cub->mlx.mlx, &cub->directions.west);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, \
		cub->map.width * 32, cub->map.height * 32, "cub3D");
	cub->player = cub_get_player_pos(cub->map.map);
	cub->player.angle = cub_get_angle(cub->player.c);
	cub_draw_map(cub, cub->map.map, -1);
	cub_draw_view_line(cub);
	mlx_mouse_hide(cub->mlx.mlx, cub->mlx.win);
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, \
		cub->map.width * MMAP_SZ / 2, \
		cub->map.height * MMAP_SZ / 2);
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, &cub_key_handler, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, NoEventMask, &cub_exit, cub);
	mlx_loop_hook(cub->mlx.mlx, &cub_render, cub);
	mlx_loop(cub->mlx.mlx);
}
