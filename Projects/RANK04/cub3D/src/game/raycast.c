/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:43:55 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/11 19:56:13 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_raycast_part_1(t_cub *cub, int x)
{
	cub->raycast.camera_x = 2 * x / (double)cub->mlx.screen_size - 1;
	cub->raycast.ray_dir_x = cub->player.dir_x + cub->player.plane_x \
		* cub->raycast.camera_x;
	cub->raycast.ray_dir_y = cub->player.dir_y + cub->player.plane_y \
		* cub->raycast.camera_x;
	cub->raycast.map_x = (int)cub->player.pos_x;
	cub->raycast.map_y = (int)cub->player.pos_y;
	if (cub->raycast.ray_dir_x == 0)
		cub->raycast.delta_dist_x = pow(10.0, 30.0);
	else
		cub->raycast.delta_dist_x = cub_double_abs(1 / cub->raycast.ray_dir_x);
	if (cub->raycast.ray_dir_y == 0)
		cub->raycast.delta_dist_y = pow(10.0, 30.0);
	else
		cub->raycast.delta_dist_y = cub_double_abs(1 / cub->raycast.ray_dir_y);
}

void	cub_raycast_part_2(t_cub *cub)
{
	cub->raycast.hit = 0;
	if (cub->raycast.ray_dir_x < 0)
	{
		cub->raycast.step_x = -1;
		cub->raycast.side_dist_x = (cub->player.pos_x - \
			cub->raycast.map_x) * cub->raycast.delta_dist_x;
	}
	else
	{
		cub->raycast.step_x = 1;
		cub->raycast.side_dist_x = (cub->raycast.map_x + 1.0 - \
			cub->player.pos_x) * cub->raycast.delta_dist_x;
	}
	if (cub->raycast.ray_dir_y < 0)
	{
		cub->raycast.step_y = -1;
		cub->raycast.side_dist_y = (cub->player.pos_y - \
			cub->raycast.map_y) * cub->raycast.delta_dist_y;
	}
	else
	{
		cub->raycast.step_y = 1;
		cub->raycast.side_dist_y = (cub->raycast.map_y + 1.0 - \
			cub->player.pos_y) * cub->raycast.delta_dist_y;
	}
}

void	cub_raycast_part_3(t_cub *cub)
{
	while (cub->raycast.hit == 0)
	{
		if (cub->raycast.side_dist_x < cub->raycast.side_dist_y)
		{
			cub->raycast.side_dist_x += cub->raycast.delta_dist_x;
			cub->raycast.map_x += cub->raycast.step_x;
			cub->raycast.side = 0;
		}
		else
		{
			cub->raycast.side_dist_y += cub->raycast.delta_dist_y;
			cub->raycast.map_y += cub->raycast.step_y;
			cub->raycast.side = 1;
		}
		if (cub->map.map[cub->raycast.map_x][cub->raycast.map_y] == '1')
			cub->raycast.hit = 1;
	}
	if (cub->raycast.side == 0)
		cub->raycast.perp_wall_dist = (cub->raycast.side_dist_x - \
			cub->raycast.delta_dist_x);
	else
		cub->raycast.perp_wall_dist = (cub->raycast.side_dist_y - \
			cub->raycast.delta_dist_y);
}

void	cub_raycast_part_4(t_cub *cub, int x)
{
	t_img	*img;

	img = cub_get_wall(cub);
	cub_raycast_util_1(cub);
	cub_raycast_draw_wall(cub, img, x);
	cub_draw_floor_and_ceiling(cub, x);
}

void	cub_raycast(t_cub *cub)
{
	auto int x = -1;
	while (++x < cub->mlx.screen_size)
	{
		cub_raycast_part_1(cub, x);
		cub_raycast_part_2(cub);
		cub_raycast_part_3(cub);
		cub_raycast_part_4(cub, x);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, \
		cub->frames.frames[1].img, \
		cub->mlx.screen_size / 2 - cub->frames.frames[0].width / 2, \
		cub->mlx.screen_size - cub->frames.frames[0].height);
}
