/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 08:01:11 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/02 18:06:02 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_small_check(t_cub *cub, double x, double y)
{
	char	*char_1;
	char	*char_2;

	char_1 = &cub->map.map[(int)((cub->player.y + y) / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	char_2 = &cub->map.map[(int)((cub->player.y) / MMAP_SZ)] \
		[(int)((cub->player.x + x) / MMAP_SZ)];
	auto char *old_c = &cub->map.map[(int)(cub->player.y / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	cub_clear_circle(cub, cub->player.x, cub->player.y, -1);
	if (*char_1 != '1' && *char_1 != '-')
		cub->player.y += y;
	if (*char_2 != '1' && *char_2 != '-')
		cub->player.x += x;
	auto char *new_c = &cub->map.map[(int)(cub->player.y / MMAP_SZ)] \
		[(int)(cub->player.x / MMAP_SZ)];
	if (*old_c != *new_c)
	{
		*new_c = *old_c;
		*old_c = '0';
		cub_mmap_check(cub, true);
	}
	else
		cub_mmap_check(cub, false);
}

void	cub_check_keys(t_cub *cub)
{
	if (cub->keys.right)
		cub_update_angle(cub, 1);
	else if (cub->keys.left)
		cub_update_angle(cub, -1);
	if (cub->keys.w)
		cub_move_player(cub, cos(cub->player.angle * M_PI / 180.0) * STEP, \
			sin(cub->player.angle * M_PI / 180.0) * STEP);
	else if (cub->keys.s)
		cub_move_player(cub, -cos(cub->player.angle * M_PI / 180.0) * STEP, \
			-sin(cub->player.angle * M_PI / 180.0) * STEP);
	else if (cub->keys.a)
		cub_move_player(cub, -cos((cub->player.angle + 90) * M_PI / \
			180.0) * STEP, -sin((cub->player.angle + 90) * M_PI / 180.0) \
			* STEP);
	else if (cub->keys.d)
		cub_move_player(cub, cos((cub->player.angle + 90) * M_PI / \
			180.0) * STEP, sin((cub->player.angle + 90) * M_PI / 180.0) \
			* STEP);
}
