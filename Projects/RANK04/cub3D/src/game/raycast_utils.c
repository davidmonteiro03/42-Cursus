/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:11:30 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/08 19:46:36 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_raycast_util_1(t_cub *cub)
{
	cub->raycast.line_height = (int)(cub->mlx.screen_size / \
		cub->raycast.perp_wall_dist);
	cub->raycast.draw_start = -cub->raycast.line_height / 2 + \
		cub->mlx.screen_size / 2;
	if (cub->raycast.draw_start < 0)
		cub->raycast.draw_start = 0;
	cub->raycast.draw_end = cub->raycast.line_height / 2 + \
		cub->mlx.screen_size / 2;
	if (cub->raycast.draw_end >= cub->mlx.screen_size)
		cub->raycast.draw_end = cub->mlx.screen_size - 1;
	if (cub->raycast.side == 0)
		cub->raycast.wall_x = cub->player.pos_y + cub->raycast.perp_wall_dist * \
			cub->raycast.ray_dir_y;
	else
		cub->raycast.wall_x = cub->player.pos_x + cub->raycast.perp_wall_dist * \
			cub->raycast.ray_dir_x;
	cub->raycast.wall_x -= floor(cub->raycast.wall_x);
}

void	cub_raycast_draw_wall(t_cub *cub, t_img *img, int x)
{
	auto int tex_x = (int)(cub->raycast.wall_x * (double)img->width);
	if (cub->raycast.side == 0 && cub->raycast.ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	if (cub->raycast.side == 1 && cub->raycast.ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	auto double step = 1.0 * img->height / cub->raycast.line_height;
	auto double tex_pos = (cub->raycast.draw_start - cub->mlx.screen_size / 2 + \
		cub->raycast.line_height / 2) * step;
	auto int y = cub->raycast.draw_start - 1;
	while (++y < cub->raycast.draw_end)
	{
		auto int tex_y = (int)tex_pos & (img->height - 1);
		tex_pos += step;
		auto unsigned int color;
		color = img->textures[img->width * tex_y + tex_x];
		if (!(y < MINIMAP * (cub->map.minimap_size * 2 + 1) + STROKE && \
			x < MINIMAP * (cub->map.minimap_size * 2 + 1) + STROKE))
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x, y, color);
	}
}

void	cub_draw_floor_and_ceiling(t_cub *cub, int x)
{
	auto int aux_y = -1;
	while (++aux_y < cub->raycast.draw_start)
		if (!(aux_y < MINIMAP * (cub->map.minimap_size * 2 + 1) + STROKE && \
			x < MINIMAP * (cub->map.minimap_size * 2 + 1) + STROKE))
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				x, aux_y, cub->ceiling.hex);
	aux_y = cub->raycast.draw_end - 1;
	while (++aux_y < cub->mlx.screen_size - 1)
		if (!(aux_y < MINIMAP * (cub->map.minimap_size * 2 + 1) + STROKE && \
			x < MINIMAP * (cub->map.minimap_size * 2 + 1) + STROKE))
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, \
				x, aux_y, cub->floor.hex);
}

t_img	*cub_get_wall(t_cub *cub)
{
	t_img	*img;

	if (cub->raycast.side == 0 && cub->raycast.ray_dir_x > 0)
		img = &cub->directions.south;
	else if (cub->raycast.side == 0 && cub->raycast.ray_dir_x < 0)
		img = &cub->directions.north;
	else if (cub->raycast.side == 1 && cub->raycast.ray_dir_y > 0)
		img = &cub->directions.east;
	else
		img = &cub->directions.west;
	return (img);
}
