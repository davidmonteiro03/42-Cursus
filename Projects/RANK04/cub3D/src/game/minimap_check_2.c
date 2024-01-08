/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_check_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:23:12 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/08 23:21:34 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	cub_draw_mmap_4(t_cub *cub, bool draw)
{
	auto int alt_y = -1, x;
	auto int y = cub->map.height - (cub->map.minimap_size * 2 + 1) - 1;
	while (++alt_y < cub->map.minimap_size * 2 + 1)
	{
		++y;
		x = -1;
		while (++x < cub->map.minimap_size * 2 + 1)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = x * MINIMAP;
				cub->tmp.y = alt_y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, x, alt_y);
	}
	cub_draw_last_line(cub, x, alt_y);
	cub_small_update(cub);
}

void	cub_draw_mmap_5(t_cub *cub, bool draw)
{
	auto int alt_y = -1, alt_x;
	auto int y = cub->map.height - (cub->map.minimap_size * 2 + 1) - 1;
	while (++alt_y < cub->map.minimap_size * 2 + 1)
	{
		++y;
		alt_x = -1;
		auto int x = cub->map.width - (cub->map.minimap_size * 2 + 1) - 1;
		while (++alt_x < cub->map.minimap_size * 2 + 1)
		{
			++x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MINIMAP;
				cub->tmp.y = alt_y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, alt_x, alt_y);
	}
	cub_draw_last_line(cub, alt_x, alt_y);
	cub_small_update(cub);
}

void	cub_draw_mmap_6(t_cub *cub, bool draw)
{
	auto int alt_y = -1, alt_x;
	auto int y = cub->map.height - (cub->map.minimap_size * 2 + 1) - 1;
	while (++alt_y < cub->map.minimap_size * 2 + 1)
	{
		++y;
		alt_x = -1;
		auto int x = (int)cub->player.pos_y - cub->map.minimap_size - 1;
		while (++x < (int)cub->player.pos_y - \
			cub->map.minimap_size + cub->map.minimap_size * 2 + 1)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MINIMAP;
				cub->tmp.y = alt_y * MINIMAP;
			}
		}
		cub_draw_last_column(cub, alt_x + 1, alt_y);
	}
	cub_draw_last_line(cub, alt_x + 1, alt_y);
	cub_small_update(cub);
}

void	cub_mmap_check_2(t_cub *cub, bool draw)
{
	if ((int)cub->player.pos_y - cub->map.minimap_size < 0)
		cub_draw_mmap_4(cub, draw);
	else if ((int)cub->player.pos_y + cub->map.minimap_size \
		> cub->map.width - 1)
		cub_draw_mmap_5(cub, draw);
	else
		cub_draw_mmap_6(cub, draw);
}
