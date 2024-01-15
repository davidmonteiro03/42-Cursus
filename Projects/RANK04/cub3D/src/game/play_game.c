/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:31:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/15 09:50:59 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	cub_render(t_cub *cub)
{
	auto int time = clock(), old_time = 0, x, y;
	mlx_mouse_get_pos(cub->mlx.mlx, cub->mlx.win, &x, &y);
	cub_check_keys(cub, x, y);
	cub_raycast(cub);
	old_time = time;
	time = clock();
	auto double frame_time = (time - old_time) / 1000.0;
	cub->player.move_speed = frame_time / 100.0;
	cub->player.rot_speed = frame_time / 175.0;
	return (0);
}

void	cub_loop_game(t_cub *cub)
{
	cub->map.map[(int)cub->player.pos_x][(int)cub->player.pos_y] = ' ';
	cub_mmap_check(cub, true);
	cub_draw_player(cub, false);
	mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, \
		cub->mlx.screen_size / 2, cub->mlx.screen_size / 2);
	mlx_hook(cub->mlx.win, KeyPress, KeyPressMask, &cub_key_press, cub);
	mlx_hook(cub->mlx.win, KeyRelease, KeyReleaseMask, &cub_key_release, cub);
	mlx_hook(cub->mlx.win, DestroyNotify, StructureNotifyMask, &cub_exit, cub);
	mlx_loop_hook(cub->mlx.mlx, &cub_render, cub);
	mlx_loop(cub->mlx.mlx);
}
