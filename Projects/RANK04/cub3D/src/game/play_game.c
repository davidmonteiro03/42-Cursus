/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:31:24 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/12 11:31:33 by dcaetano         ###   ########.fr       */
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
	cub->player.move_speed = frame_time / 450.0;
	cub->player.rot_speed = frame_time / 650.0;
	return (0);
}

void	cub_loop_game(t_cub *cub)
{
	cub->frames.len = 2;
	cub->frames.frames = (t_img *)malloc(sizeof(t_img) * cub->frames.len);
	cub->frames.frames[0] = cub_img_init("./worlds/42/textures/redbrick.xpm");
	cub->frames.frames[1] = cub_img_init("./worlds/david/textures/me.xpm");
	cub_finish_img(cub->mlx.mlx, &cub->frames.frames[0]);
	cub_finish_img(cub->mlx.mlx, &cub->frames.frames[1]);
	cub->frames.size = cub->frames.frames[0].width;
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
