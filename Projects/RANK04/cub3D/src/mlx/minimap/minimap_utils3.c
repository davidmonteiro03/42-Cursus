/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/04 00:37:45 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_draw_mmap_7(t_cub *cub, bool draw)
{
	auto int alt_y = -1, x;
	auto int y = (int)(cub->player.y / MMAP_SZ) - cub->map.minimap - 1;
	while (++y < (int)(cub->player.y / MMAP_SZ) - \
		cub->map.minimap + cub->map.minimap * 2 + 1)
	{
		++alt_y;
		x = -1;
		while (++x < cub->map.minimap * 2 + 1)
		{
			if (draw)
				cub_check_shape(cub, x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
		}
		cub_draw_last_column(cub, x, alt_y);
	}
	cub_draw_last_line(cub, x, alt_y + 1);
	cub_small_update(cub);
}

void	cub_draw_mmap_8(t_cub *cub, bool draw)
{
	auto int alt_y = -1, alt_x;
	auto int y = (int)(cub->player.y / MMAP_SZ) - cub->map.minimap - 1;
	while (++y < (int)(cub->player.y / MMAP_SZ) - \
		cub->map.minimap + cub->map.minimap * 2 + 1)
	{
		++alt_y;
		auto int x = cub->map.width - (cub->map.minimap * 2 + 1) - 1;
		alt_x = -1;
		while (++alt_x < cub->map.minimap * 2 + 1)
		{
			++x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
		}
		cub_draw_last_column(cub, alt_x, alt_y);
	}
	cub_draw_last_line(cub, alt_x, alt_y + 1);
	cub_small_update(cub);
}

void	cub_draw_mmap_9(t_cub *cub, bool draw)
{
	auto int alt_y = -1, alt_x;
	auto int y = (int)(cub->player.y / MMAP_SZ) - cub->map.minimap - 1;
	while (++y < (int)(cub->player.y / MMAP_SZ) - \
		cub->map.minimap + cub->map.minimap * 2 + 1)
	{
		++alt_y;
		alt_x = -1;
		auto int x = (int)(cub->player.x / MMAP_SZ) - cub->map.minimap - 1;
		while (++x < (int)(cub->player.x / MMAP_SZ) - \
			cub->map.minimap + cub->map.minimap * 2 + 1)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, alt_y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = alt_y * MMAP_SZ;
			}
		}
		cub_draw_last_column(cub, alt_x + 1, alt_y);
	}
	cub_draw_last_line(cub, alt_x + 1, alt_y + 1);
	cub_small_update(cub);
}
