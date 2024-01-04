/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:32:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 23:56:53 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_back(t_cub *cub)
{
	auto int y = -1;
	while (++y < 350)
	{
		auto int x = -1;
		while (++x < 700)
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				x, y, cub->ceiling.hex);
	}
	while (++y < 700)
	{
		auto int x = -1;
		while (++x < 700)
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				x, y, cub->floor.hex);
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
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, 700, 700, "cub3D");
	cub->player = cub_get_player_pos(cub->map.map);
	cub->player.angle = cub_get_angle(cub, cub->player.c);
	cub->map.minimap = (int)(ft_min(cub->map.width, cub->map.height) - 1) / 2;
	if (cub->map.minimap > MINIMAP)
		cub->map.minimap = MINIMAP;
	cub_draw_back(cub);
	cub_mmap_check(cub, true);
	cub_draw_player(cub, false);
}

void	cub_mlx(t_cub *cub)
{
	cub_init_mlx(cub);
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, 350, 350);
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, &cub_press_key, cub);
	mlx_hook(cub->mlx.win, KeyRelease, KeyReleaseMask, &cub_release_key, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, NoEventMask, &cub_exit, cub);
	mlx_mouse_hook(cub->mlx.win, &cub_mouse_handler, cub);
	mlx_loop_hook(cub->mlx.mlx, &cub_render, cub);
	mlx_loop(cub->mlx.mlx);
}
