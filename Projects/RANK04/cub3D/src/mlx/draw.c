/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:32:12 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/23 01:00:57 by dcaetano         ###   ########.fr       */
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
}

void	cub_init_mlx(t_cub *cub)
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
	cub->mlx.win_size = ft_max(cub->map.width, cub->map.height) * \
		MMAP_SZ * 2 + MMAP_SZ * 7;
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, cub->mlx.win_size, \
		cub->mlx.win_size, "cub3D");
	cub->player = cub_get_player_pos(cub->map.map);
	cub->player.angle = cub_get_angle(cub, cub->player.c);
	cub_draw_map(cub, cub->map.map, -1);
	cub_draw_view_line(cub);
	cub_draw_circle(cub, cub->player.x, cub->player.y, -1);
}

void	cub_mlx(t_cub *cub)
{
	cub_init_mlx(cub);
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, \
		cub->map.width * MMAP_SZ / 2, \
		cub->map.height * MMAP_SZ / 2);
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, &cub_press_key, cub);
	mlx_hook(cub->mlx.win, KeyRelease, KeyReleaseMask, &cub_release_key, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, NoEventMask, &cub_exit, cub);
	mlx_mouse_hook(cub->mlx.win, &cub_mouse_handler, cub);
	mlx_loop_hook(cub->mlx.mlx, &cub_render, cub);
	mlx_loop(cub->mlx.mlx);
}
