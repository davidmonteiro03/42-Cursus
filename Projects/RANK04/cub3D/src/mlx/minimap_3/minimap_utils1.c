/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:06:22 by dcaetano          #+#    #+#             */
/*   Updated: 2024/01/03 21:30:55 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3D.h"

void	cub_draw_mmap_c_1(t_cub *cub, bool draw)
{
	auto int y = -1;
	while (++y < MMAP_SZ_3)
	{
		auto int x = -1;
		while (++x < MMAP_SZ_3)
		{
			if (draw)
				cub_check_shape(cub, x, y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = x * MMAP_SZ;
				cub->tmp.y = y * MMAP_SZ;
			}
		}
	}
	cub_small_update_c(cub);
}

void	cub_draw_mmap_c_2(t_cub *cub, bool draw)
{
	auto int y = -1;
	while (++y < MMAP_SZ_3)
	{
		auto int x = cub->map.width - MMAP_SZ_3 - 1;
		auto int alt_x = -1;
		while (++alt_x < MMAP_SZ_3)
		{
			++x;
			if (draw)
				cub_check_shape(cub, alt_x, y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = y * MMAP_SZ;
			}
		}
	}
	cub_small_update_c(cub);
}

void	cub_draw_mmap_c_3(t_cub *cub, bool draw)
{
	auto int y = -1;
	while (++y < MMAP_SZ_3)
	{
		auto int alt_x = -1;
		auto int x = (int)(cub->player.x / MMAP_SZ) - MMAP_3 - 1;
		while (++x < (int)(cub->player.x / MMAP_SZ) - MMAP_3 + MMAP_SZ_3)
		{
			++alt_x;
			if (draw)
				cub_check_shape(cub, alt_x, y, cub->map.map[y][x]);
			if (cub->map.map[y][x] == cub->player.c)
			{
				cub->tmp.x = alt_x * MMAP_SZ;
				cub->tmp.y = y * MMAP_SZ;
			}
		}
	}
	cub_small_update_c(cub);
}
