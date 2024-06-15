/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_check_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:34:51 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/15 08:50:04 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_mmap_7(t_cub *cub, bool draw)
{
	auto int alt_y = -1, x = 0;
	auto int y = (int)cub->player.pos_x - cub->map.minimap_size - 1;
	while (++y < (int)cub->player.pos_x - \
		cub->map.minimap_size + cub->map.minimap_size * 2 + 1)
	{
		++alt_y;
		x = -1;
		while (++x < cub->map.minimap_size * 2 + 1)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			if (y == (int)cub->player.pos_x && x == (int)cub->player.pos_y)
			{
				cub->tmp.x = x * MINIMAP;
				cub->tmp.y = alt_y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, x, alt_y);
	}
	cub_draw_last_line(cub, x, alt_y + 1);
	cub_small_update(cub);
}

void	cub_draw_mmap_8(t_cub *cub, bool draw)
{
	auto int alt_y = -1, alt_x = 0;
	auto int y = (int)cub->player.pos_x - cub->map.minimap_size - 1;
	while (++y < (int)cub->player.pos_x - \
		cub->map.minimap_size + cub->map.minimap_size * 2 + 1)
	{
		++alt_y;
		auto int x = cub->map.width - (cub->map.minimap_size * 2 + 1) - 1;
		alt_x = -1;
		while (++alt_x < cub->map.minimap_size * 2 + 1)
		{
			++x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (y == (int)cub->player.pos_x && x == (int)cub->player.pos_y)
			{
				cub->tmp.x = alt_x * MINIMAP;
				cub->tmp.y = alt_y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, alt_x, alt_y);
	}
	cub_draw_last_line(cub, alt_x, alt_y + 1);
	cub_small_update(cub);
}

void	cub_draw_mmap_9(t_cub *cub, bool draw)
{
	auto int alt_y = -1, alt_x = 0;
	auto int y = (int)cub->player.pos_x - cub->map.minimap_size - 1;
	while (++y < (int)cub->player.pos_x - \
		cub->map.minimap_size + cub->map.minimap_size * 2 + 1)
	{
		++alt_y;
		alt_x = -1;
		auto int x = (int)cub->player.pos_y - cub->map.minimap_size - 1;
		while (++x < (int)cub->player.pos_y - \
			cub->map.minimap_size + cub->map.minimap_size * 2 + 1)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (y == (int)cub->player.pos_x && x == (int)cub->player.pos_y)
			{
				cub->tmp.x = alt_x * MINIMAP;
				cub->tmp.y = alt_y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, alt_x + 1, alt_y);
	}
	cub_draw_last_line(cub, alt_x + 1, alt_y + 1);
	cub_small_update(cub);
}

void	cub_mmap_check_3(t_cub *cub, bool draw)
{
	if ((int)cub->player.pos_y - cub->map.minimap_size < 0)
		cub_draw_mmap_7(cub, draw);
	else if ((int)cub->player.pos_y + cub->map.minimap_size \
		> cub->map.width - 1)
		cub_draw_mmap_8(cub, draw);
	else
		cub_draw_mmap_9(cub, draw);
}
