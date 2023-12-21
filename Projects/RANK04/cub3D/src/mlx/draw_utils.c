/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:12:50 by dcaetano          #+#    #+#             */
/*   Updated: 2023/12/21 06:13:23 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_circle(t_cub *cub, int x, int y, int i)
{
	while (++i < PLAYER_SZ * 2)
	{
		auto int j = -1;
		while (++j < PLAYER_SZ * 2)
		{
			if ((i - PLAYER_SZ) * (i - PLAYER_SZ) + (j - PLAYER_SZ) * \
				(j - PLAYER_SZ) < PLAYER_SZ * PLAYER_SZ)
				mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
					PLAYER_SZ + i, y - PLAYER_SZ + j, \
					cub_contrast_color(cub->floor.hex, 0x000000, 0xFFFFFF));
		}
	}
}

void	cub_clear_circle(t_cub *cub, int x, int y, int i)
{
	while (++i < PLAYER_SZ * 2)
	{
		auto int j = -1;
		while (++j < PLAYER_SZ * 2)
		{
			if ((i - PLAYER_SZ) * (i - PLAYER_SZ) + (j - PLAYER_SZ) * \
				(j - PLAYER_SZ) < PLAYER_SZ * PLAYER_SZ)
			{
				auto char c = cub->map.map[(int)((y - PLAYER_SZ + j) / \
					MMAP_SZ)][(int)((x - PLAYER_SZ + i) / MMAP_SZ)];
				if (c == '1')
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, cub->ceiling.hex);
				else if (c == '-')
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, 0x999999);
				else if (c == '0' || c == ' ' || ft_strchr("NSEW", c))
					mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, x - \
						PLAYER_SZ + i, y - PLAYER_SZ + j, cub->floor.hex);
			}
		}
	}
}

void	cub_draw_view_line(t_cub *cub)
{
	auto double view_angle = 90;
	auto int ray_count = 1000;
	auto int i = -1;
	while (++i < ray_count)
	{
		auto double ray_angle = cub->player.angle - (view_angle / 2) + \
			(view_angle * i / ray_count);
		auto double ray_x = cos(ray_angle * M_PI / 180.0);
		auto double ray_y = sin(ray_angle * M_PI / 180.0);
		auto double x = cub->player.x;
		auto double y = cub->player.y;
		while (x >= 0 && y >= 0 && x < cub->map.width * MMAP_SZ && \
			y < cub->map.height * MMAP_SZ && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '1' && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '-')
		{
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, (int)x, (int)y, \
				cub_contrast_color(cub->floor.hex, 0x007700, 0x00FF00));
			x += ray_x;
			y += ray_y;
		}
	}
	cub_draw_circle(cub, cub->player.x, cub->player.y, -1);
}

void	cub_draw_view_line_left(t_cub *cub, double *old_angle)
{
	if (old_angle)
		printf("%f %d\n", *old_angle, cub->player.angle);
	auto double view_angle = 90;
	auto int ray_count = 1000;
	auto int i = -1;
	while (++i < ray_count)
	{
		auto double ray_angle = cub->player.angle - (view_angle / 2) + \
			(view_angle * i / ray_count);
		auto double ray_x = cos(ray_angle * M_PI / 180.0);
		auto double ray_y = sin(ray_angle * M_PI / 180.0);
		auto double x = cub->player.x;
		auto double y = cub->player.y;
		while (x >= 0 && y >= 0 && x < cub->map.width * MMAP_SZ && \
			y < cub->map.height * MMAP_SZ && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '1' && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '-')
		{
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, (int)x, (int)y, \
				cub_contrast_color(cub->floor.hex, 0x007700, 0x00FF00));
			x += ray_x;
			y += ray_y;
		}
	}
	cub_draw_circle(cub, cub->player.x, cub->player.y, -1);
}

void	cub_draw_view_line_right(t_cub *cub, double *old_angle)
{
	if (old_angle)
	{
		auto double view_angle = 90;
		auto double ray_angle = *old_angle - (view_angle / 2);
		auto double x = cub->player.x;
		auto double y = cub->player.y;
		while (x >= 0 && y >= 0 && x < cub->map.width * MMAP_SZ && \
			y < cub->map.height * MMAP_SZ && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '1' && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '-')
		{
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, (int)x, (int)y,
				cub->floor.hex);
			x += cos(ray_angle * M_PI / 180.0);
			y += sin(ray_angle * M_PI / 180.0);
		}
	}
	auto double view_angle = 90;
	auto int ray_count = 1000;
	auto int i = -1;
	auto int frst_ray_angle = (int)(cub->player.angle - (view_angle / 2));
	while (++i < ray_count)
	{
		auto double ray_angle = cub->player.angle - (view_angle / 2) + \
			(view_angle * i / ray_count);
		auto double x = cub->player.x;
		auto double y = cub->player.y;
		auto int color = cub_contrast_color(cub->floor.hex, 0x007700, 0x00FF00);
		if ((int)ray_angle == frst_ray_angle || \
			(int)ray_angle == frst_ray_angle + 1)
			color = cub->floor.hex;
		while (x >= 0 && y >= 0 && x < cub->map.width * MMAP_SZ && \
			y < cub->map.height * MMAP_SZ && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '1' && \
			cub->map.map[(int)(y / MMAP_SZ)][(int)(x / MMAP_SZ)] != '-')
		{
			mlx_pixel_put(cub->mlx.mlx, cub->mlx.win, (int)x, (int)y, color);
			x += cos(ray_angle * M_PI / 180.0);
			y += sin(ray_angle * M_PI / 180.0);
		}
	}
	cub_draw_circle(cub, cub->player.x, cub->player.y, -1);
}

void	cub_check_field_of_view(t_cub *cub, double *old_angle, bool left, bool right)
{
	if (left && right)
		return (cub_draw_view_line_left(cub, NULL), \
			cub_draw_view_line_right(cub, NULL));
	if (left)
		return (cub_draw_view_line_left(cub, old_angle));
	if (right)
		return (cub_draw_view_line_right(cub, old_angle));
	cub_draw_view_line(cub);
}
