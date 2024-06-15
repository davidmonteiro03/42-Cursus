/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_check_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:55:43 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/15 08:48:39 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_mmap_1(t_cub *cub, bool draw)
{
	auto int y = -1, x = 0;
	while (++y < cub->map.minimap_size * 2 + 1)
	{
		x = -1;
		while (++x < cub->map.minimap_size * 2 + 1)
		{
			if (draw)
				cub_check_shape(cub, x, y, cub->map.map[y][x]);
			if (y == (int)cub->player.pos_x && x == (int)cub->player.pos_y)
			{
				cub->tmp.x = x * MINIMAP;
				cub->tmp.y = y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, x, y);
	}
	cub_draw_last_line(cub, x, y);
	cub_small_update(cub);
}

void	cub_draw_mmap_2(t_cub *cub, bool draw)
{
	auto int y = -1, alt_x = 0;
	while (++y < cub->map.minimap_size * 2 + 1)
	{
		auto int x = cub->map.width - (cub->map.minimap_size * 2 + 1) - 1;
		alt_x = -1;
		while (++alt_x < cub->map.minimap_size * 2 + 1)
		{
			++x;
			if (draw)
				cub_check_shape(cub, alt_x, y, cub->map.map[y][x]);
			if (y == (int)cub->player.pos_x && x == (int)cub->player.pos_y)
			{
				cub->tmp.x = alt_x * MINIMAP;
				cub->tmp.y = y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, alt_x, y);
	}
	cub_draw_last_line(cub, alt_x, y);
	cub_small_update(cub);
}

void	cub_draw_mmap_3(t_cub *cub, bool draw)
{
	auto int y = -1, alt_x = 0;
	while (++y < cub->map.minimap_size * 2 + 1)
	{
		alt_x = -1;
		auto int x = (int)cub->player.pos_y - cub->map.minimap_size - 1;
		while (++x < (int)cub->player.pos_y - cub->map.minimap_size \
			+ cub->map.minimap_size * 2 + 1)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, y, cub->map.map[y][x]);
			if (y == (int)cub->player.pos_x && x == (int)cub->player.pos_y)
			{
				cub->tmp.x = alt_x * MINIMAP;
				cub->tmp.y = y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, alt_x + 1, y);
	}
	cub_draw_last_line(cub, alt_x + 1, y);
	cub_small_update(cub);
}

void	cub_mmap_check_1(t_cub *cub, bool draw)
{
	if ((int)cub->player.pos_y - cub->map.minimap_size < 0)
		cub_draw_mmap_1(cub, draw);
	else if ((int)cub->player.pos_y + cub->map.minimap_size > \
		cub->map.width - 1)
		cub_draw_mmap_2(cub, draw);
	else
		cub_draw_mmap_3(cub, draw);
}
