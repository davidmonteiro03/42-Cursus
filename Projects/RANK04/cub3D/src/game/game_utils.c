/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:41:57 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/10 17:28:07 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_mmap_check(t_cub *cub, bool draw)
{
	if ((int)cub->player.pos_x - cub->map.minimap_size < 0)
		cub_mmap_check_1(cub, draw);
	else if ((int)cub->player.pos_x + cub->map.minimap_size \
		> cub->map.height - 1)
		cub_mmap_check_2(cub, draw);
	else
		cub_mmap_check_3(cub, draw);
}

void	cub_update_angle(t_cub *cub, int angle)
{
	cub_draw_player(cub, true);
	auto double oldDirX = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(cub->player.rot_speed * angle) \
		- cub->player.dir_y * sin(cub->player.rot_speed * angle);
	cub->player.dir_y = oldDirX * sin(cub->player.rot_speed * angle) + \
		cub->player.dir_y * cos(cub->player.rot_speed * angle);
	auto double oldPlaneX = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(cub->player.rot_speed \
		* angle) - cub->player.plane_y * sin(cub->player.rot_speed * angle);
	cub->player.plane_y = oldPlaneX * sin(cub->player.rot_speed * angle) + \
		cub->player.plane_y * cos(cub->player.rot_speed * angle);
	cub_draw_player(cub, false);
}

void	cub_move_player(t_cub *cub, double x, double y)
{
	cub_draw_player(cub, true);
	auto char char_x = \
		cub->map.map[(int)(cub->player.pos_x + x)][(int)cub->player.pos_y];
	auto char char_y = \
		cub->map.map[(int)cub->player.pos_x][(int)(cub->player.pos_y + y)];
	auto char *old_c = \
		&cub->map.map[(int)cub->player.pos_x][(int)cub->player.pos_y];
	if (char_x != '1' && char_x != '-')
		cub->player.pos_x += x;
	if (char_y != '1' && char_y != '-')
		cub->player.pos_y += y;
	auto char *new_c = \
		&cub->map.map[(int)cub->player.pos_x][(int)cub->player.pos_y];
	if (*old_c != *new_c && *new_c != '1' && *new_c != '-')
	{
		auto char tmp_c = *new_c;
		*new_c = *old_c;
		*old_c = tmp_c;
		cub_mmap_check(cub, true);
	}
	else
		cub_mmap_check(cub, false);
	cub_draw_player(cub, false);
}

void	cub_check_keys(t_cub *cub, int x, int y)
{
	if (cub->keys.esc)
		cub_exit(cub);
	if (cub->keys.right || (x > cub->mlx.screen_size - 200 && \
		x < cub->mlx.screen_size && y > 0 && y < cub->mlx.screen_size))
		cub_update_angle(cub, -1);
	if (cub->keys.left || (x > 0 && x < 200 && \
		y > 0 && y < cub->mlx.screen_size))
		cub_update_angle(cub, 1);
	if (cub->keys.w)
		cub_move_player(cub, cub->player.dir_x * cub->player.move_speed, \
			cub->player.dir_y * cub->player.move_speed);
	if (cub->keys.s)
		cub_move_player(cub, cub->player.dir_x * -cub->player.move_speed, \
			cub->player.dir_y * -cub->player.move_speed);
	if (cub->keys.a)
		cub_move_player(cub, cub->player.dir_y * -cub->player.move_speed, \
			cub->player.dir_x * cub->player.move_speed);
	if (cub->keys.d)
		cub_move_player(cub, cub->player.dir_y * cub->player.move_speed, \
			cub->player.dir_x * -cub->player.move_speed);
}
