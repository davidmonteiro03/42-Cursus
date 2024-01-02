/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:32:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/02 17:51:15 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
	cub->back.red = 0x99;
	cub->back.green = 0x99;
	cub->back.blue = 0x99;
	cub->back.hex = 0x999999;
	if (cub->map.width > MINIMAP)
		cub_mmap_check(cub, true);
}

void	cub_mlx(t_cub *cub)
{
	cub_init_mlx(cub);
	cub->tmp.x = (int)(cub->player.x) % ((MINIMAP * 2 + 1) * MMAP_SZ);
	cub->tmp.y = (int)(cub->player.y) % ((MINIMAP * 2 + 1) * MMAP_SZ);
	cub_draw_circle(cub, cub->player.x, cub->player.y, -1);
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, \
		cub->player.x, cub->player.y);
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, &cub_press_key, cub);
	mlx_hook(cub->mlx.win, KeyRelease, KeyReleaseMask, &cub_release_key, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, NoEventMask, &cub_exit, cub);
	mlx_mouse_hook(cub->mlx.win, &cub_mouse_handler, cub);
	mlx_loop_hook(cub->mlx.mlx, &cub_render, cub);
	mlx_loop(cub->mlx.mlx);
}
